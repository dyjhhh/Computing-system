gcc -g -o debug debug.c
./debug <input.txt >output.txt
diff output.txt out.txt
