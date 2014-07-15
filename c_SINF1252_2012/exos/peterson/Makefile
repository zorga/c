CC = gcc
CFLAGS = -Werror -Wall -std=c99 -pthread -g

all: clean thread_peterson
	## For the glory of Satan, make run or die!!! ##

peterson: thread_peterson.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@rm -rf thread_peterson

run: thread_peterson
	./thread_peterson
