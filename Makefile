# Define the compiler to use
CC=gcc

# Specify compiler flags
CFLAGS=-Iinclude

# Automatically find all .c files in the src/ directory
SRC=$(wildcard src/*.c)

# Convert the .c filenames to .o to specify the object file names
OBJ=$(SRC:src/%.c=build/%.o)

# Define the target executable name
TARGET=build/my_project

# Default target: build the project
all: $(TARGET)

# Rule to link the program - depends on all object files
$(TARGET): $(OBJ)
$(CC) -o $@ $^

# Rule to compile source files into object files
build/%.o: src/%.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean target: remove object files and the executable
clean:
    rm -f $(OBJ) $(TARGET)

# Run target: execute the built program
run: $(TARGET)
    ./$(TARGET)