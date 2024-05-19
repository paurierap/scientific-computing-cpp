# Makefile structure:
# target: prerequisites
#	commands

# DO NOT COMPILE HEADER FILES!

# Variables to control Makefile operation
LIB_DIR = lib
MAIN_DIR = .

# Find all the C++ files we want to compile
SRCS := $(shell find $(LIB_DIR) -name '*.cpp')

# Prepends MAIN_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./your_dir/hello.cpp.o
OBJS := $(SRCS:$(LIB_DIR)/%=%.o)

# Compilation flags
CXX = g++
CXXFLAGS = -Wall -O #-I /$(INC_DIR)

# Debugging flags
# CXXFLAGS = -g

# $^ references all prerequisites, and $@ references the target name
Driver: Driver.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

Driver.o: $(MAIN_DIR)/Driver.cpp
	$(CXX) $(CXXFLAGS) -c $^

# Build step for C++ source
%.cpp.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# "$ make clean" to remove all object files
clean:
	rm *.o