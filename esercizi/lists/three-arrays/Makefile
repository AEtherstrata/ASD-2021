all: main.c list.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c list.c -o ../build/lata-test -I.

run: all
	@../build/lata-test