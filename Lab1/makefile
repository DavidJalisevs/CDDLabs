#Name: Davids Jalisevs
#License: GNU General Public License 3.0

OBJS = Semaphore.o signal.o
SOURCE = Semaphore.cpp signal.cpp
HEADER = Semaphore.h
OUT = signal.out
CC = g++
FLAGS = -g -c -Wall
LFLAGS =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	make clean
clean:
	rm -f $(OBJS)
