OBJS	= Bag.o BagIterator.o ShortTest.o ExtendedTest.o App.o
SOURCE	= Bag.cpp BagIterator.cpp ShortTest.cpp ExtendedTest.cpp App.cpp
HEADER	= Bag.h BagIterator.h ShortTest.h ExtendedTest.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: clean $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Bag.o:Bag.cpp
	$(CC) $(FLAGS) Bag.cpp

BagIterator.o:BagIterator.cpp
	$(CC) $(FLAGS) BagIterator.cpp

ShortTest.o:ShortTest.cpp
	$(CC) $(FLAGS) ShortTest.cpp

ExtendedTest.o:ExtendedTest.cpp
	$(CC) $(FLAGS) ExtendedTest.cpp

App.o: App.cpp
	$(CC) $(FLAGS) App.cpp

clean:
	rm -f $(OBJS) $(OUT) *.gch


ExtendedTest.o:ExtendedTest.cpp
	$(CC) $(FLAGS) ExtendedTest.cpp
