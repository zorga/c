string: string.o string.h
	gcc -Wall -Werror -o string string.c

string.o: string.h
	gcc -o string.o string.h
clean:
	rm *.o
mrproper: clean
	rm string

