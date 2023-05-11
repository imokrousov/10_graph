setup: compile-lib compile-exec 
	g++ -o main main.o graph.o

compile-lib:
	g++ -c -o graph.o graph.cpp

compile-exec:
	g++ -c -o main.o main.cpp

clean:
	rm graph.o
	rm main.o