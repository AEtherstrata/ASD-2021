all: main.c queue.c test.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c queue.c test.c -o ../build/queue-test -I.

run: all
	@../build/-test
