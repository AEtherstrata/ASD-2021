all: main.c struct.c test.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c struct.c test.c -o ../build/struct-test -I.

run: all
	@../build/struct-test
