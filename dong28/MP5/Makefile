CC=gcc
CFLAGS= -g -Wall -Werror -Wextra

mp5: main.o codebreaker.o
	$(CC) $(CFLAGS) main.o codebreaker.o -o mp5

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

codebreaker.o: codebreaker.c
	$(CC) $(CLFAGS) -c codebreaker.c

clean:
	rm -f *.o mp5
