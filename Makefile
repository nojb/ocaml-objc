all: objc.cmx objc_stubs.o test.cmx
	ocamlopt -cclib -lobjc -cclib "-framework cocoa" $^

test.cmi test.cmx: test.ml
	ocamlopt -c $^

objc.cmi objc.cmx: objc.mli objc.ml
	ocamlopt -c $^

objc_stubs.o: objc_stubs.c
	clang -I `ocamlc -where` -c $<
