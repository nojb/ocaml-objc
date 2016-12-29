type id
type klass
type sel
type meth

external objc_getClassList: unit -> klass array = "caml_objc_getClassList"
external class_getName: klass -> string = "caml_class_getName"
external class_createInstance: klass -> int -> id = "caml_class_createInstance"
external objc_allocateClassPair: klass -> string -> int -> klass option = "caml_objc_allocateClassPair"
external objc_registerClassPair: klass -> unit = "caml_objc_registerClassPair"
external objc_getClass: string -> klass option = "caml_objc_getClass"
external sel_registerName: string -> sel = "caml_sel_registerName"
external class_getClassMethod: klass -> sel -> meth = "caml_class_getClassMethod"
external class_copyMethodList: klass -> meth array = "caml_class_copyMethodList"
external method_getName: meth -> sel = "caml_method_getName"
external sel_getName: sel -> string = "caml_sel_getName"
