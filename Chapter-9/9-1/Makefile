# Makefile structure:
# target: prerequisites
#	commands

# DO NOT COMPILE HEADER FILES!

# Variables to control Makefile operation
LIB_DIR = ./lib

# Compilation flags
CXX = g++
CXXFLAGS = -Wall -O #-I /$(INC_DIR)

# $^ references all prerequisites, and $@ references the target name
main: main.o Exception.o FileNotOpenException.o OutOfRangeException.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $^

%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^

# Run "$ make clean" to remove all object files
clean:
	rm *.o