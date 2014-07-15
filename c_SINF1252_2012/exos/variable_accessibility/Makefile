CC=gcc
CFLAGS= -Wall -Werror -g -std=c99 -pthread

all: clean access

access: access.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf access

.PHONY: clean

run:
	./access
