CC = g++
INCLUDE_LIB = -I./include

all: raytracer

raytracer: main.o
	$(CC) -o raytracer *.o $(INCLUDE_LIB)

main.o:
	$(CC) $(INCLUDE_LIB) -c main.cpp

clean:
	rm -f *.o raytracer
	
