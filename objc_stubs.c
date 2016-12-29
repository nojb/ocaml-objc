#include <limits.h>

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>

#include <objc/runtime.h>

#define Val_klass(klass) ((value)(klass))
#define Klass_val(v) ((Class)(v))
#define Val_id(id) ((value)(id))
#define Id_val(v) ((id)(v))

CAMLprim value caml_objc_getClassList (value unit)
{
  CAMLparam1(unit);
  CAMLlocal1(res);
  Class *classList;
  int bufferCount = objc_getClassList (NULL, INT_MAX);
  classList = calloc (bufferCount, sizeof (Class));
  objc_getClassList (classList, bufferCount);
  res = caml_alloc (bufferCount, 0);
  for (int i = 0; i < bufferCount; i ++)
    Field (res, i) = Val_klass(classList[i]);
  free (classList);
  CAMLreturn(res);
}

CAMLprim value caml_class_getName (value klass)
{
  CAMLparam1(klass);
  CAMLlocal1(res);
  const char *s = class_getName (Klass_val(klass));
  res = caml_copy_string (s);
  CAMLreturn(res);
}

CAMLprim value caml_class_createInstance (value klass, value extraBytes)
{
  CAMLparam2(klass, extraBytes);
  CAMLlocal1(res);
  res = Val_id(class_createInstance (Klass_val(klass), Int_val(extraBytes)));
  CAMLreturn(res);
}
