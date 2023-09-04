
all: main

run: main
	./main

main: main.o datetime.o
	g++ -g -o main main.o datetime.o

main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

datetime.o: datetime.cpp datetime.hpp
	g++ -g -c datetime.cpp -std=c++11

clean:
	del main.exe *.o *~