# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Iinclude -Ofast

# raylib library directory
RAYLIB_DIR = /usr/local/include

# raylib library flags
RAYLIB_CFLAGS = -I$(RAYLIB_DIR)/src -DPLATFORM_DESKTOP
RAYLIB_LDFLAGS = -L$(RAYLIB_DIR)/src -lraylib -ldl -lpthread -lm

# Source directory
SRC_DIR = src

# Build directory
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Executable name
EXECUTABLE = sandgame

# Default target
all: $(BUILD_DIR) $(EXECUTABLE)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile C source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(RAYLIB_CFLAGS) -c $< -o $@

# Link object files with raylib
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(RAYLIB_LDFLAGS)

# Clean up object files and executable
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

# Phony target to prevent conflicts with files named 'clean'
.PHONY: clean
