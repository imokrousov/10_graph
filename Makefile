<<<<<<< HEAD
first: main.cpp hello.cpp
	g++ -o hello hello.cpp main.cpp

second: 
	echo "Haha$(\n)"
=======
main: first second
	g++ -o main main.o graph.o

first: main.cpp
	g++ -c main.cpp

second: graph.cpp
	g++ -c graph.cpp

clean:
	rm -rf *.o 
	rm -rf *.exe
>>>>>>> master
