#include <iostream>
#include "graph.h"
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main_inf = 2e9;

vector<pair<int, int>> get_random_pairs() {
	srand(time(0));
	int ln = rand() % 20;
	vector <pair<int, int>> v(ln);
	for (int i = 0; i < ln; ++i) {
		v[i] = make_pair(rand() % ln, rand() % ln);
	}
	return v;
}

int main(){
	cout << "FIRST GRAPH:\n";
	Graph g1 = make_g(get_random_pairs());
	print_graph(g1);
	cout << "SECOND GRAPH:\n";
	vector <pair<int, int>> p = get_random_pairs();
	vector <Edge> es;
	for (int i = 0; i < p.size(); ++i) {
		es.push_back(make_e(p[i].first, p[i].second, rand() % 100));
	}
	Graph g2 = make_g(es);
	print_graph(g2, false);
	cout << "THIRD GRAPH:\n";
	srand(time(0));
	int ln = rand() % 20;
	int** m = new int* [ln];
	for (int i = 0; i < ln; ++i) {
		m[i] = new int[ln];
	}
	for (int i = 0; i < ln; ++i) {
		for (int j = 0; j < ln; ++j) {
			m[i][j] = main_inf;
		}
	}
	for (int i = 0; i < ln * ln / 5; ++i) {
		m[rand() % ln][rand() % ln] = rand() % 100;
	}
	Graph g3 = make_g(m, ln);
	print_graph(g3);
	return 0;
}
