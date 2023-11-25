CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
LINKER_FLAGS = -lGL -lglfw -lGLEW -lcglm

SRC_DIR = src
BIN_DIR = bin

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/shaderLoader.c
EXEC = $(BIN_DIR)/exec

buildrun: $(SRCS)
		$(CC) $(CFLAGS) -g -o $(EXEC) $(SRCS) $(LINKER_FLAGS)
		./$(EXEC)

build: $(SRCS)
		$(CC) $(CFLAGS) -g -o $(EXEC) $(SRCS) $(LINKER_FLAGS)

run: $(EXEC)
		./$(EXEC)
