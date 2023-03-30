#Name: Davids Jalisevs
#Date: 31/03/2023
#License: GNU General Public License 3.0

#Define the compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -pthread

#Define the target executable
TARGET_EXEC = producer

#Define the source and object files
SRCS = SafeBuffer.cpp Semaphore.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

#Define phony targets
.PHONY: all debug clean doc

#Default target: build the executable
all: $(TARGET_EXEC)

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

#build the executable with debugging symbols and flags
debug: CXXFLAGS += -DDEBUG -Wall -g
debug: all

#compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#remove all object files and the executable
clean:
	rm -f $(OBJS) $(TARGET_EXEC)

#generate documentation using Doxygen
doc:
	doxygen

#Dependencies
SafeBuffer.o: SafeBuffer.h
Semaphore.o: Semaphore.h
main.o: SafeBuffer.h Semaphore.h
