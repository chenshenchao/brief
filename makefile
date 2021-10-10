out/brief: out \
		main/grammar/brief.bison.c \
		main/grammar/brief.bison.h \
		main/grammar/brief.flex.c \
		main/runtime/any.c \
		main/runtime/any.h \
		main/runtime/array.c \
		main/runtime/array.h \
		main/runtime/heap.c \
		main/runtime/heap.h \
		main/runtime/node.c \
		main/runtime/node.h \
		main/runtime/object.c \
		main/runtime/object.h \
		main/runtime/scope.c \
		main/runtime/scope.h \
		main/runtime/stack.c \
		main/runtime/stack.h \
		main/runtime/string.c \
		main/runtime/string.h \
		main/interpreter.c \
		main/console.c
	gcc -o out/brief \
		main/grammar/brief.flex.c \
		main/grammar/brief.bison.c \
		main/runtime/any.c \
		main/runtime/array.c \
		main/runtime/heap.c \
		main/runtime/node.c \
		main/runtime/object.c \
		main/runtime/scope.c \
		main/runtime/stack.c \
		main/runtime/string.c \
		main/interpreter.c \
		main/console.c
out:
	mkdir -p out
main/grammar/brief.bison.c main/grammar/brief.bison.h: \
		main/grammar/brief.y
	bison -o main/grammar/brief.bison.c -d main/grammar/brief.y
main/grammar/brief.flex.c: \
		main/grammar/brief.l
	flex -o main/grammar/brief.flex.c main/grammar/brief.l

.PHONY: clean
clean:
	rm -rf out
	rm -f main/grammar/brief.*.c
	rm -f main/grammar/brief.*.h
