main: graph.o main.o
	g++ -o main main.o graph.o

graph.o: graph.cpp
	g++ -c graph.cpp -o graph.o 

main.o: main.cpp
	g++ -c main.cpp -o main.o 

clean:
	rm graph.o
	rm main.o
