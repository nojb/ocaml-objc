type id
type klass
type sel
type meth

val objc_getClassList: unit -> klass array
val class_getName: klass -> string
val class_createInstance: klass -> int -> id
val objc_allocateClassPair: klass -> string -> int -> klass option
val objc_registerClassPair: klass -> unit
val objc_getClass: string -> klass option
val sel_registerName: string -> sel
val class_getClassMethod: klass -> sel -> meth
val class_copyMethodList: klass -> meth array
val method_getName: meth -> sel
val sel_getName: sel -> string
