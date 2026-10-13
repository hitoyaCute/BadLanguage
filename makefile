# Compiler
CC  = gcc
CXX = g++

# Compile flags
RELEASE_ARGS = -01
DEBUG_ARGS   = 
CFLAGS       = -Wall -std=c23 $(DEBUG_ARGS) 

# Source files
SRC = ./src/main.c \
	  ./src/tokenizer.c

# Include directories
INCLUDE_FOLDERS = include \
                  src     \

# Intermediate variables
INC   = $(addprefix -I, $(INCLUDE_FOLDERS))
BUILD = build
OBJ   = $(SRC:%.c=$(BUILD)/%.o)
BIN   = $(BUILD)/run

.PHONY: all clean rebuild

# Default target
all: $(BIN) compile_commands.json

# Link
$(BIN): $(OBJ) | $(BUILD)
	$(CC) $(CFLAGS) $(INC) -o $@ $^

# Compile
$(BUILD)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Create build directory
$(BUILD):
	mkdir -p $(BUILD)

# Regenerate compile_commands.json when Makefile changes
compile_commands.json: makefile
	bear -- $(MAKE) $(OBJ) --no-print-directory -B

# Remove build artifacts
clean:
	rm -rf $(BUILD) compile_commands.json

# Clean then rebuild
rebuild: clean all
