all: main.c contains.c test.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c ../stack/stack.c contains.c test.c -o ../build/contains-test -I.

run: all
	@../build/contains-test
