#include <iostream>
#include "graph.h"

using namespace std;

int main(){
	int **mat = make_matrix(3);
	int buf[3][3] = {{0, 1, 0},{1, 1, 1},{1, 0, 1}};
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			mat[i][j] = buf[i][j];
		}
	}
	Graph g = make_g(mat,3);
	print_graph(g);
	cout << '\n';
	print_graph(g, false);
}