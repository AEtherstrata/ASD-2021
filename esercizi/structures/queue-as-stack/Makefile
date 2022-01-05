all: main.c queue-as-stack.c test.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c ../stack/stack.c queue-as-stack.c test.c -o ../build/qas-test -I.

run: all
	@../build/qas-test
