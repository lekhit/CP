# Makefile to compile and run the Complete Mediation test program.

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# The target executable
TARGET = mediation_test

# Default target: build the executable
all: $(TARGET)

# Rule to build the executable from the C source file
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

# Rule to run the program
run: $(TARGET)
	@echo "--- Running Mediation Test ---"
	./$(TARGET)
	@echo "--- Test Finished ---"
	@echo "Check contents of testfile.txt to verify the second write occurred."
	@cat testfile.txt

# Rule to clean up build artifacts and test files
clean:
	rm -f $(TARGET) testfile.txt

.PHONY: all run clean