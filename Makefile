CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

all:
		$(CC) $(CFLAGS) -g -o gl0.out gl0.c shader_loader.c -lGL -lglfw -lGLEW
