TARGET = main
SRC_FILE = $(TARGET).cpp

CC = g++
CFLAGS = -lm -std=c++14

all: clean build run

build:
	$(CC) $(SRC_FILE) -o $(TARGET) 

run:
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
