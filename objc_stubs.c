#include <limits.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <objc/runtime.h>

#define Val_klass(klass) ((value)(klass))
#define Klass_val(v) ((Class)(v))
#define Val_id(id) ((value)(id))
#define Id_val(v) ((id)(v))
#define Val_sel(sel) ((value)(sel))
#define Sel_val(v) ((SEL)(v))
#define Val_method(meth) ((value)(meth))
#define Meth_val(v) ((Method)(v))
#define Val_meth(m) ((value)(m))

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

CAMLprim value caml_objc_allocateClassPair (value klass, value name, value extraBytes)
{
  CAMLparam3(klass, name, extraBytes);
  CAMLlocal1(res);
  Class cls = objc_allocateClassPair (Klass_val(klass), String_val(name), Int_val(extraBytes));
  res = Val_int(0);
  if (cls != Nil) {
    res = caml_alloc (1, 0);
    Field (res, 0) = Val_klass(cls);
  }
  CAMLreturn(res);
}

CAMLprim value caml_objc_registerClassPair (value klass)
{
  CAMLparam1(klass);
  objc_registerClassPair(Klass_val(klass));
  CAMLreturn(Val_unit);
}

CAMLprim value caml_objc_getClass (value name)
{
  CAMLparam1(name);
  CAMLlocal1(res);
  Class v = objc_getClass(String_val(name));
  res = Val_int(0);
  if (v != nil) {
    res = caml_alloc (1, 0);
    Field (res, 0) = Val_id(v);
  }
  CAMLreturn(res);
}

CAMLprim value caml_sel_registerName (value name)
{
  CAMLparam1 (name);
  CAMLlocal1 (res);
  res = Val_sel(sel_registerName(String_val(name)));
  CAMLreturn (res);
}

CAMLprim value caml_class_getClassMethod (value klass, value sel)
{
  CAMLparam2 (klass, sel);
  CAMLlocal1 (res);
  Method meth = class_getClassMethod (Klass_val(klass), Sel_val(sel));
  res = Val_int(0);
  if (meth != NULL) {
    res = caml_alloc (1, 0);
    Field (res, 0) = Val_method(meth);
  }
  CAMLreturn (res);
}

CAMLprim value caml_class_copyMethodList (value klass)
{
  CAMLparam1 (klass);
  CAMLlocal1 (res);
  unsigned int outCount;
  Method *meths = class_copyMethodList (Klass_val(klass), &outCount);
  res = caml_alloc (outCount, 0);
  for (int i = 0; i < outCount; i ++)
    Field (res, i) = Val_meth(meths[i]);
  free (meths);
  CAMLreturn (res);
}

CAMLprim value caml_method_getName (value meth)
{
  CAMLparam1 (meth);
  CAMLlocal1 (res);
  res = Val_sel(method_getName(Meth_val(meth)));
  CAMLreturn (res);
}

CAMLprim value caml_sel_getName (value sel)
{
  CAMLparam1 (sel);
  CAMLlocal1 (res);
  res = caml_copy_string (sel_getName (Sel_val(sel)));
  CAMLreturn (res);
}
