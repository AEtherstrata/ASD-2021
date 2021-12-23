all: main.c stack.c
	@if [ ! -d "build" ]; then \
		mkdir build; \
	fi
	gcc main.c stack.c -o build/structures-test -I.

run: all
	@./build/structures-test
