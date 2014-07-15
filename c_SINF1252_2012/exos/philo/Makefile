CC = gcc
CFLAGS = -Werror -pthread -std=c99 -g

all: clean philosophe
	## Lancez le programme avec make run ##

philo: philosophe.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f philosophe

.PHONY: clean

run: philosophe
	./philosophe
