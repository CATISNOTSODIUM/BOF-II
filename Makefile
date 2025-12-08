# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Iinclude
LDFLAGS = -lncurses

# Project structure
TARGET = bof
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Source and object files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "Clean complete"

# Clean only object files
cleanobj:
	rm -rf $(OBJDIR)
	@echo "Object files removed"

# Phony targets
.PHONY: all clean cleanobj

# Debug: print variables
debug:
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TARGET: $(TARGET)"