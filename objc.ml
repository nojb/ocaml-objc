type klass

external objc_getClassList: unit -> klass array = "caml_objc_getClassList"
external objc_class_getName: klass -> string = "caml_class_getName"

let () =
  Array.iter (fun k -> print_endline (objc_class_getName k)) (objc_getClassList ())
