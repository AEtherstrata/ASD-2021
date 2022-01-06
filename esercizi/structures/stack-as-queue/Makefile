all: main.c stack-as-queue.c test.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c ../queue/queue.c stack-as-queue.c test.c -o ../build/saq-test -I.

run: all
	@../build/saq-test
