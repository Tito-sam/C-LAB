CC = gcc
CFLAGS = -Wall -Wextra -std=c17
LDFLAGS = -lm

SRC = src/main.c src/fisica.c src/simulacion.c src/datos.c
OBJ = $(SRC:.c=.o)

TARGET = clab

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)