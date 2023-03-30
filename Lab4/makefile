#Name: Davids Jalisevs
#Date: 30/03/2023
#License: GNU General Public License 3.0

#Define object files, source, header,output, compiler and other flags
OBJS = Semaphore.o main.o Barrier.o
SOURCE = Semaphore.cpp main.cpp Barrier.cpp
HEADER = Semaphore.h Barrier.h
OUT = main.out
CC = g++
LFLAGS =

#build all object files and link them into the output, -g is for debug, wall is for warnings
all: $(OBJS)
	$(CC) -g $(OBJS) -Wall -o $(OUT) $(LFLAGS)
	make clean

clean:
	rm -f $(OBJS)

#all cleans are cleaning there 

#-g is enabling debbuging mode
#-c generates object code for seperae files
# clean is cleaning the whole thing after

