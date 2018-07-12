CC = g++
INCLUDE_LIB = -I./glm-0.9.9.0

all: raytracer

raytracer: main.o
	$(CC) -o raytracer *.o $(INCLUDE_LIB)

main.o:
	$(CC) $(INCLUDE_LIB) -c main.cpp

clean:
	rm -f *.o raytracer
	
