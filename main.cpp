#include "graph.h"
#include <iostream>
#include <set>

using namespace std;

int main(){
	cout << "start..." << endl;
	vector<Edge> e;
	e.push_back({1,2,3});
	e.push_back({1,3,3});
	e.push_back({4,2,3});
	e.push_back({3,4,3});
	Graph g = make_g(e);
	print_graph(g);
}