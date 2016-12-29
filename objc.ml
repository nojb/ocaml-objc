type id
type klass

external objc_getClassList: unit -> klass array = "caml_objc_getClassList"
external class_getName: klass -> string = "caml_class_getName"
external class_createInstance: klass -> int -> id = "caml_class_createInstance"
external objc_allocateClassPair: klass -> string -> int -> klass option = "caml_objc_allocateClassPair"
external objc_registerClassPair: klass -> unit = "caml_objc_registerClassPair"
external objc_getClass: string -> klass option = "caml_objc_getClass"
