all: main.c stack.c list.c queue.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c stack.c list.c queue.c -o ../build/dll-test -I.

run: all
	@../build/dll-test
