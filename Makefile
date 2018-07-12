CC = g++
INCLUDE_LIB = -I./glm-0.9.9.0

all: raytracer

raytracer: main.o
	$(CC) $(INCLUDE_LIB) -o raytracer *.o

main.o:
	g++ -c main.cpp

clean:
	rm -f *.o raytracer
	
