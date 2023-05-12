#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.h"

using namespace std;

int main(){
	int** a = new int*[4];
	for (int i = 0; i < 4; ++i) {
		a[i] = new int[4];
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = abs(i - j) % 2;
		}
	}
	vector <Edge> edg(5);
	for (int i = 0; i < 5; ++i) {
		edg[i].from = (i + 1) % 5;
		edg[i].to = (i + 2) % 5;
		edg[i].weight = i;
	}
	vector <pair <int, int> > vec = {
		{ 0, 1 },
		{ 0, 2 },
		{ 1, 3 },
		{ 1, 4 },
		{ 2, 4 },
		{ 3, 5 },
	};
	Graph g;
	g = make_g(a, 4);
	print_graph(g, false);
	cout << "\n\n\n";
	g = make_g(edg, 5);
	print_graph(g, true);
	cout << "\n\n\n";
	g = make_g(vec, 6);
	print_graph(g, true);
	return 0;
}