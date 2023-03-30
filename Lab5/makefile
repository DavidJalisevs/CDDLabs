#Name: Davids Jalisevs
#Date: 31/03/2023
#License: GNU General Public License 3.0
# buld file name 
TARGET_EXEC := producer_consumer

CC=g++
CFLAGS= -std=c++11 -pthread

#every .o file depends on .cpp file with the same name
%.o: %.cpp
		$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# link .o and compile them with make
ALL: SafeBuffer.o Semaphore.o main.o 
		$(CC) -o ${TARGET_EXEC} SafeBuffer.o Semaphore.o main.o $(CFLAGS) $(DEBUGFLAGS)

#-g is enabling debbuging mode
DEBUG: DEBUGFLAGS = -DDEBUG -Wall
DEBUG: ALL

.PHONY: doc CLEAN

doc: 

		rm -rf doc/
		doxygen

#this is customary and just deletes all .o files
CLEAN:
		rm *.o

#-c generates object code for seperae files
# clean is cleaning the whole thing after

