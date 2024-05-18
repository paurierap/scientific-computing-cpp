# Makefile structure:
# target: prerequisites
#	commands

# DO NOT COMPILE HEADER FILES!
# There must be a more compact way to do this, but this works jeje

# Variables to control Makefile operation
LIB_DIR = lib
MAIN_DIR = .

# Find all the C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(LIB_DIR) -name '*.cpp')

# Prepends MAIN_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./your_dir/hello.cpp.o
OBJS := $(SRCS:$(LIB_DIR)/%=%.o)

# Compilation flags
CXX = g++
CXXFLAGS = -Wall -O #-I /$(INC_DIR)

# $^ references all prerequisites, and $@ references the target name
Driver: Driver.o $(OBJS) #BoundaryConditions.o FiniteDifferenceGrid.o LinearSystem.o Matrix.o Vector.o BvpOde.o
	$(CXX) $(CXXFLAGS) $^ -o $@

Driver.o: $(MAIN_DIR)/Driver.cpp
	$(CXX) $(CXXFLAGS) -c $^

# Build step for C++ source
%.cpp.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

#AbstractOdeSolver.o: $(LIB_DIR)/AbstractOdeSolver.cpp
#	$(CXX) $(CXXFLAGS) -c $^

#ForwardEulerSolver.o: $(LIB_DIR)/ForwardEulerSolver.cpp
#	$(CXX) $(CXXFLAGS) -c $^

#RungeKuttaSolver.o: $(LIB_DIR)/RungeKuttaSolver.cpp
#	$(CXX) $(CXXFLAGS) -c $^

# Run "$ make clean" to remove all object files
clean:
	rm *.o