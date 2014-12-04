CC=g++
CFLAGS=-g -Wall

mp12: main.o mp12.o
	$(CC) $(CFLAGS) main.o mp12.o -o mp12

main.o:
	$(CC) $(CLFAGS) -c main.c

mp12.o:
	$(CC) $(CFLAGS) -c mp12.c

clean:
	rm -f *.o mp12
