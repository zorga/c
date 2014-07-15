TARGET = interfacevelos
CC = gcc
CFLAGS = -Wall -W -pipe -I. 

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)




clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

