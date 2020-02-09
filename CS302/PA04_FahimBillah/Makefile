OBJS	= proj4.o binarySearchTree.o
SOURCE	= proj4.cpp binarySearchTree.cpp
HEADER	= binarySearchTree.h binaryNode.h
OUT	= proj4
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

proj4.o: proj4.cpp
	$(CC) $(FLAGS) proj4.cpp

binarySearchTree.o: binarySearchTree.cpp
	$(CC) $(FLAGS) binarySearchTree.cpp


clean:
	rm -f $(OBJS) $(OUT)
