CC=g++
CFLAGS=-Wall -ansi

TARGET=solver.out
SOURCE=main.cpp puzzle.cpp

solver.out:	main.cpp puzzle.cpp puzzle.h CPUTimer.h
	$(CC) $(CFLAGS) -o $(TARGET) -g $(SOURCE)

clean:	
	rm -f $(TARGET)
