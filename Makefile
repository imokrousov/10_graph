all: main

first: 
	echo "Haha$(\n)"

main: main.o graph.o
	g++ main.o graph.o -o a

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp
	g++ -c graph.cpp
