type id
type klass

val objc_getClassList: unit -> klass array
val class_getName: klass -> string
val class_createInstance: klass -> int -> id
val objc_allocateClassPair: klass -> string -> int -> klass option
val objc_registerClassPair: klass -> unit
val objc_getClass: string -> klass option
