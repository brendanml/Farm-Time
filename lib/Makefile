# Makefile for a simple C++ project using clang++

# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -lraylib

# Source file and executable name
SRCS = main.cpp grass.cpp config.cpp tree.cpp
EXEC = game

# Build target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS)

# Clean target to remove the executable
clean:
	rm -f $(EXEC)
