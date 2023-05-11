all: main_exec

main_exec: ./build/graph.o main.cpp
	mkdir -p ./build/
	g++ -o ./build/main_exec main.cpp ./build/graph.o

./build/graph.o: graph.cpp
	mkdir -p ./build/
	g++ -o ./build/graph.o -c graph.cpp
clean:
	rm -rf *.o

