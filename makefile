
runtime_sources = $(shell ls main/runtime/*.c)
runtime_headers = $(shell ls main/runtime/*.h)
syntax_sources = $(shell ls main/syntax/*.c)
syntax_headers = $(shell ls main/syntax/*.h)

out/brief: out \
		main/grammar/brief.h \
		main/grammar/brief.bison.c \
		main/grammar/brief.bison.h \
		main/grammar/brief.flex.c \
		$(runtime_headers) \
		$(runtime_sources) \
		$(syntax_headers) \
		$(syntax_sources) \
		main/interpreter.c \
		main/console.c
	gcc -o out/brief \
		main/grammar/brief.flex.c \
		main/grammar/brief.bison.c \
		$(runtime_sources) \
		$(syntax_sources) \
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
