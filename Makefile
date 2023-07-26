# Compiler and compiler flags
CC := gcc
CFLAGS := -Wall -Wextra

# Source file and output binary
SRC := cuboid.c
OUT := test

# Default target
all: $(OUT)

# Build the binary
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Build the binary with debugging information
debug: CFLAGS += -g
debug: $(OUT)

# Clean the generated files
clean:
	rm -rf $(OUT) test.*
