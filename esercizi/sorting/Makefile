all: common.c main.c test.c quick-sort.c merge-sort.c bubble-sort.c selection-sort.c insertion-sort.c
	@if [ ! -d "build" ]; then \
		mkdir build; \
	fi
	gcc common.c main.c test.c quick-sort.c merge-sort.c bubble-sort.c selection-sort.c insertion-sort.c -o build/sorting-test -I.

run: all
	@./build/sorting-test
