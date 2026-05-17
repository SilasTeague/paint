CC = gcc

CFLAGS = $(shell sdl2-config --cflags) $(shell pkg-config --cflags SDL2_image)
LIBS = $(shell sdl2-config --libs) $(shell pkg-config --libs SDL2_image)

SRC = main.c cursor.c render.c input.c canvas.c paint.c
OUT = paint

all:
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
