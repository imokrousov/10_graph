#include <iostream>
#include "graph.h"

using namespace std;

int main(){
	
	Edge e1 = make_e(0,4,3);
	Edge e2 = make_e(1,2,1);
	Edge e3 = make_e(3,4,12);
	Edge e4 = make_e(4,1,2);
	Edge e5 = make_e(0,2,6);
	vector<Edge> e;
	e.push_back(e1);
	e.push_back(e2);
	e.push_back(e3);
	e.push_back(e4);
	e.push_back(e5);
	print_edge(e1);
	print_edge(e2);
	Graph g = make_g(e);
	cerr << "test\n";
	print_graph(g, true);
	print_graph(g, false);
	return 0;
}