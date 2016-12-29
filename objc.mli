type id
type klass

val objc_getClassList: unit -> klass array
val objc_class_getName: klass -> string
val class_createInstance: klass -> int -> id
