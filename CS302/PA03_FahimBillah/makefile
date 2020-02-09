OBJS	= proj3.o
SOURCE	= proj3.cpp
HEADER	=
OUT	= proj3
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

proj3.o: proj3.cpp
	$(CC) $(FLAGS) proj3.cpp


clean:
	rm -f $(OBJS) $(OUT)
