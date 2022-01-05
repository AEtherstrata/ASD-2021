all: main.c stack.c test.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c stack.c test.c -o ../build/stack-test -I.

run: all
	@../build/stack-test
