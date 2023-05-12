all: graph main
	g++ main.o graph.o -o main

graph:
	g++ -c graph.cpp  -o graph.o 

main:
	g++ -c main.cpp -o main.o

clean:
	rm -rf *.o main