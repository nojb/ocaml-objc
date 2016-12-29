open Objc

let () =
  Array.iter (fun k -> print_endline (class_getName k)) (objc_getClassList ());
  let cls =
    match objc_getClass "NSObject" with
    | Some obj -> obj
    | None -> failwith "NSObject: no class"
  in
  print_endline (class_getName cls)
