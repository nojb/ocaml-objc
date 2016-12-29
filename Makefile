all: objc.cmx objc_stubs.o
	ocamlopt -cclib -lobjc $^

objc.cmi objc.cmx: objc.mli objc.ml
	ocamlopt -c objc.mli objc.ml

objc_stubs.o: objc_stubs.c
	clang -I `ocamlc -where` -c $<
