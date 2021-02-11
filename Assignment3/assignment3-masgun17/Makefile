all: install test

install:
	gcc -std=c99 -g floyd_warshall.c

test: a.out
	./a.out input.txt
