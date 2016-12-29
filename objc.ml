type id
type klass

external objc_getClassList: unit -> klass array = "caml_objc_getClassList"
external class_getName: klass -> string = "caml_class_getName"
external class_createInstance: klass -> int -> id = "caml_class_createInstance"
external objc_allocateClassPair: klass -> string -> int -> klass option = "caml_objc_allocateClassPair"
external objc_registerClassPair: klass -> unit = "caml_objc_registerClassPair"
external objc_getClass: string -> klass option = "caml_objc_getClass"


let () =
  (* Array.iter (fun k -> print_endline (objc_class_getName k)) (objc_getClassList ()); *)
  let cls =
    match objc_getClass "NSObject" with
    | Some obj -> obj
    | None -> failwith "NSObject: no class"
  in
  print_endline (class_getName cls)
