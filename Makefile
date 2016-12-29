all: objc.cmx objc_stubs.o test.cmx
	ocamlopt -cclib -lobjc -cclib "-framework cocoa" $^

test.cmi test.cmx: objc.cmi objc.cmx
	ocamlopt -c test.ml

objc.cmi objc.cmx: objc.mli objc.ml
	ocamlopt -c objc.mli objc.ml

objc_stubs.o: objc_stubs.c
	clang -I `ocamlc -where` -c $<
