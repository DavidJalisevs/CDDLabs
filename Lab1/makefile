#Name: Davids Jalisevs
#Date: 30/03/2023
#License: GNU General Public License 3.0


#Define object files, source, header,output, compiler and other flags
OBJS = Semaphore.o signal.o
SOURCE = Semaphore.cpp signal.cpp
HEADER = Semaphore.h
OUT = signal.out
CC = g++
LFLAGS =


#build all object files and link them into the output
all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LFLAGS)
