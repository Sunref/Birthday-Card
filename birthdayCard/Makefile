CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Source files
CARD_SRCS = $(wildcard $(SRC_DIR)/*.c)
CARD_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(CARD_SRCS))

# Interface source
INTERFACE_SRC = $(SRC_DIR)/message_interface.c
INTERFACE_OBJ = $(BUILD_DIR)/message_interface.o

# Targets
CARD_TARGET = $(BIN_DIR)/birthday_animation
INTERFACE_TARGET = $(BIN_DIR)/message_interface

# Create necessary directories
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Default target
all: $(CARD_TARGET) $(INTERFACE_TARGET)

# Link birthday animation
$(CARD_TARGET): $(CARD_OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

# Link message interface
$(INTERFACE_TARGET): $(INTERFACE_OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compile birthday animation sources
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/*.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compile message interface
$(INTERFACE_OBJ): $(INTERFACE_SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

# Run the message interface
run-interface: $(INTERFACE_TARGET)
	$(INTERFACE_TARGET)

# Run the birthday animation
run-card: $(CARD_TARGET)
	$(CARD_TARGET)

.PHONY: all clean run-interface run-card
