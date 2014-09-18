CC=gcc
CFLAGS= -g -Wall -Werror -Wextra

mp4: main.o printBinary.o
	$(CC) $(CFLAGS) main.o printBinary.o -o mp4

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Uncomment to build your printBinary.c file if you chose to do the challenge
# printBinary.o: printBinary.c
#	$(CC) $(CFLAGS) -c printBinary.c

clean:
	rm -f main.o mp4
