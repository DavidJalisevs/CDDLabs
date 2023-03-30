#Name: Davids Jalisevs
#Date: 30/03/2023
#License: GNU General Public License 3.0


#Define object files, source, header,output, compiler and other flags
OBJS = Semaphore.o main.o
SOURCE = Semaphore.cpp main.cpp
HEADER = Semaphore.h 
OUT = main.out
CC = g++
LFLAGS =

#build all object files and link them into the output
all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
#Clean up objects aftrer linking
	make clean
clean:
	rm -f $(OBJS)

#THIS THING ABOVE CLEANS UP OBJECT FILES
