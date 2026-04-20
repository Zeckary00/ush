# --- Configuration ---
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -g
LDFLAGS := 
TARGET  := my_program

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := .

# Files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --- Rules ---

.PHONY: all clean valgrind run

all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Run with Valgrind to check for memory leaks
valgrind: $(TARGET)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         ./$(TARGET)

# Standard run command
run: $(TARGET)
	./$(TARGET)

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
