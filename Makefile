main: first second
	g++ -o main main.o graph.o

first: main.cpp
	g++ -c main.cpp

second: graph.cpp
	g++ -c graph.cpp

clean:
	rm -rf *.o 
	rm -rf *.exe