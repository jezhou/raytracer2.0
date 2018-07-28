CC = g++ -g
INCLUDE_LIB = -I./include

all: raytracer

new: clean all

raytracer: main.o
	$(CC) -o raytracer *.o $(INCLUDE_LIB)

main.o: camera.o sphere.o imageplane.o
	$(CC) $(INCLUDE_LIB) -c main.cpp

camera.o:
	$(CC) $(INCLUDE_LIB) -c Camera.cpp

sphere.o:
	$(CC) $(INCLUDE_LIB) -c Sphere.cpp

imageplane.o:
	$(CC) $(INCLUDE_LIB) -c ImagePlane.cpp

clean:
	rm -f *.o raytracer
	
