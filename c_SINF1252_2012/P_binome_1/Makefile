CC= gcc
#CC= clang
CFLAGS= -Werror -std=c99 -g

all : clean test_string
	## You can launch the tests with: ./test_string or make run ##

test_string: main.c my_string.o
	$(CC) $(CFLAGS) main.c my_string.o -o $@

my_string.o : my_string.c
	$(CC) $(CFLAGS) -c $< -o $@

run : test_string
	./test_string

.PHONY: clean

clean :
	@rm -f test_string *.o 
