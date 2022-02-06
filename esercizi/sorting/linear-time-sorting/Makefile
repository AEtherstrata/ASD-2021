all: common.c main.c test.c 
	@if [ ! -d "../build" ]; then \
		mkdir build; \
	fi
	gcc common.c main.c test.c -o ../build/linear-sorting-test -I.

run: all
	@../build/linear-sorting-test