all:main

main: main.o  graph.o
	g++ main.o  graph.o -o main

main.o: main.cpp
	g++ -c main.cpp



graph.o: graph.cpp
	g++ -c graph.cpp

clean:
	rm -rf *.o 
	rm -rf *.exe