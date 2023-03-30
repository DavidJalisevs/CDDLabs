#Name: Davids Jalisevs
#Date: 31/03/2023
#License: GNU General Public License 3.0

OBJS = Semaphore.o main.o Barrier.o
SOURCE = Semaphore.cpp main.cpp Barrier.cpp
HEADER = Semaphore.h Barrier.h
OUT = main.out
CC = g++
LFLAGS =


all: $(OBJS)
	$(CC) -g $(OBJS) -Wall -o $(OUT) $(LFLAGS)
	make clean

clean:
	rm -f $(OBJS)



#-g is enabling debbuging mode
#-c generates object code for seperae files
# clean is cleaning the whole thing after

