# Makefile structure:
# target: prerequisites
#	commands

# DO NOT COMPILE HEADER FILES!
# There must be a more compact way to do this, but this works jeje

# Variables to control Makefile operation
LIB_DIR = ./lib
MAIN_DIR = ./tests
INC_DIR = ./include

# Compilation flags
CXX = g++
CXXFLAGS = -Wall -O #-I /$(INC_DIR)

# $^ references all prerequisites, and $@ references the target name
main: main.o AbstractOdeSolver.o ForwardEulerSolver.o RungeKuttaSolver.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: $(MAIN_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $^

%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^

#AbstractOdeSolver.o: $(LIB_DIR)/AbstractOdeSolver.cpp
#	$(CXX) $(CXXFLAGS) -c $^

#ForwardEulerSolver.o: $(LIB_DIR)/ForwardEulerSolver.cpp
#	$(CXX) $(CXXFLAGS) -c $^

#RungeKuttaSolver.o: $(LIB_DIR)/RungeKuttaSolver.cpp
#	$(CXX) $(CXXFLAGS) -c $^

# Run "$ make clean" to remove all object files
clean:
	rm *.o