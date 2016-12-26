all: main.o
	gcc main.o -o anagram.exe


main.o: main.c
	gcc main.c -c


clean:
	rm main.o anagram.exe
