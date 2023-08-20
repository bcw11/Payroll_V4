
all: main

run: main
	./main

main: main.o 
	g++ -g -o main main.o 

main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

clean:
	del main.exe main.o *~