
#Refrence was from GEEKS4GEEKS https://www.geeksforgeeks.org/makefile-in-c-and-its-applications/
#Lost Brain Cells making this. longest part of the program. 2 youtube videos and multiple forums later I believe that there is a matrix now...


all: car_dealership

car_dealership: Driver.o Storage.o Data.o Other.o
	g++ Driver.o Storage.o Data.o Other.o -o car_dealership

Driver.o: Driver.cpp Storage.h Data.h Other.h
	g++ -c Driver.cpp

Storage.o: Storage.cpp Storage.h Data.h
	g++ -c Storage.cpp

Data.o: Data.cpp Data.h
	g++ -c Data.cpp

Other.o: Other.cpp Other.h
	g++ -c Other.cpp

clean:
	rm -f *.o car_dealership