all: main.c queue.c test.c
	@if [ ! -d "build" ]; then \
		mkdir build; \
	fi
	gcc main.c queue.c test.c -o build/structures-test -I.

run: all
	@./build/structures-test
