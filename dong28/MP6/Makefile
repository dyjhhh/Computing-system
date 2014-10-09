CC=g++
CFLAGS=-g -Wall #-Werror

all: mp7 test

mp7: main.o lodepng.o imageData.o functions.o
	$(CC) $(CFLAGS) main.o lodepng.o imageData.o functions.o -o mp7

test: test.o lodepng.o imageData.o functions.o solution.o
	$(CC) $(CFLAGS) test.o lodepng.o imageData.o functions.o solution.o -o test

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lodepng.o: lodepng.c
	$(CC) $(CFLAGS) -c lodepng.c

imageData.o: imageData.c
	$(CC) $(CFLAGS) -c imageData.c

functions.o: functions.c
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f *.o mp7
