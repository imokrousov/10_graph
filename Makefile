all: main

main: main.o graph.o
	g++ main.o graph.o -o main

graph.o: graph.cpp
	g++ -c graph.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o main
