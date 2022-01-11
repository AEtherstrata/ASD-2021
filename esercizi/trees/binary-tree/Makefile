all: main.c tree.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c tree.c -o ../build/binary-tree-test -I.

run: all
	@../build/binary-tree-test
