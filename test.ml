open Objc

let () =
  Array.iter (fun k -> print_endline (class_getName k)) (objc_getClassList ());
  let cls =
    match objc_getClass "NSApplication" with
    | Some obj -> obj
    | None -> failwith "NSObject: no class"
  in
  Array.iter (fun m -> print_endline (sel_getName (method_getName m)))
    (class_copyMethodList cls)
  (* let sel = sel_registerName "sharedApplication" in *)
  (* let meth = class_getClassMethod cls sel in *)
  (* let _obj = class_createInstance cls in *)
  (* prerr_endline "?" *)
