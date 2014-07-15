CC = gcc
CFLAGS = -Wall -Werror -g -std=c99

main: main.o LList.o
	$(CC) $(CFLAGS) -o main $^

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

LList.o: LList.c
	$(CC) $(CFLAGS) -c $< -o $@

run: main
	./main

clean:
	@rm -rf *.o main

.PHONY: clean

