CC = gcc

CFLAGS = $(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs)

SRC = paint.c cursor.c render.c input.c
OUT = paint

all:
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
