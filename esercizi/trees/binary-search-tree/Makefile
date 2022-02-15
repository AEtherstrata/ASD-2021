all: main.c tree.c
	@if [ ! -d "../build" ]; then \
		mkdir ../build; \
	fi
	gcc main.c bst.c -o ../build/binary-search-tree-test -I.

run: all
	@../build/binary-search-tree-test
