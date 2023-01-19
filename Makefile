CC = gcc
CFLAGS = -Wall -Iinclude

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

bmp_reader: $(OBJ)
	$(CC) $(OBJ) -o $(BIN_DIR)/bmp_reader

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: bmp_reader
	$(CC) $(TEST_DIR)/test.c -o $(TEST_DIR)/test -I$(INC_DIR)
	$(TEST_DIR)/test $(TEST_DIR)/test.bmp

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/bmp_reader $(TEST_DIR)/test
