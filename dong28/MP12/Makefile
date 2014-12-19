CC=g++
CFLAGS=-g -Wall

default: mp12

mp12: main.o mp12.o
	$(CC) $(CFLAGS) main.o mp12.o -o mp12

test: test.o mp12.o
	$(CC) $(CFLAGS) test.o mp12.o -o testMP12

test.o:
	$(CC) $(CFLAGS) -c test.c

main.o:
	$(CC) $(CLFAGS) -c main.c

mp12.o:
	$(CC) $(CFLAGS) -c mp12.c

clean:
	rm -f *.o mp12
