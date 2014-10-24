CC=gcc
CFLAGS=-g -std=c99 -Wall -Werror

paths: paths.c test-paths.c paths.h
	${CC} ${CFLAGS} paths.c test-paths.c -o paths

.PHONY: clean
clean:
	rm -f paths
