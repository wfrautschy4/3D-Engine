# Author: Will Frautschy

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Iinclude -Wall -Wextra -O2 -g

# Directories
SRC_DIR := src
BIN_DIR := bin
INC_DIR := include

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))
TARGET := main

# ------- Targets --------

all: $(TARGET)

headers: *.cpp tags
	./headers.sh

tags: *.cpp
	ctags -R .

# ------------------------

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create bin/ directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean generated files
clean:
	rm -rf $(BIN_DIR) $(TARGET)

.PHONY: all clean


project.zip: *.c *.h *.a makefile
	zip $@ $^
	rm -rf install
	mkdir install
	unzip $@ -d install 
	make -C install -r lab4
	make -C install -r lab4u
	sleep 1
	rm -rf install


# this is our master compiler rule to generate .o files.
# It needs all 4 flags

# %.o:%.c *.h
# 	gcc $(CFLAGS) -g -c $< -o $@
