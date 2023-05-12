main.o: main.cpp
	g++ -c main.cpp -o main.o

graph.o: graph.cpp
	g++ -c graph.cpp -o graph.o 

clean:
	rm -rf *.o 
	rm -rf *.exe