#include "graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int INF = 2e9;

Edge make_e(int _from, int _to, int _weight) {
	return Edge{ _from, _to, _weight };
}

Graph make_g(int** m, int n) {
	Graph g;
	g.matrix = m;
	vector <Edge> e;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] != INF) {
				e.push_back(make_e(i, j, m[i][j]));
			}
		}
	}
	g.edges = e;
	g.e_count = e.size();
	g.v_count = n;
	return g;
}
Graph make_g(const vector<Edge>& es) {
	Graph g;
	g.edges = es;
	int max_n = 0;
	for (int i = 0; i < es.size(); ++i) {
		max_n = max(max_n, es[i].from);
		max_n = max(max_n, es[i].to);
	}
	max_n++;
	int** m = new int* [max_n];
	for (int i = 0; i < max_n; ++i) {
		m[i] = new int[max_n];
	}
	for (int i = 0; i < max_n; ++i) {
		for (int j = 0; j < max_n; ++j) {
			m[i][j] = INF;
		}
	}
	for (int i = 0; i < es.size(); ++i) {
		m[es[i].from][es[i].to] = es[i].weight;
	}
	g.matrix = m;
	g.e_count = es.size();
	g.v_count = max_n;
	return g;
}
Graph make_g(const vector<pair<int, int>>& es) {
	Graph g;
	vector <Edge> e;
	int max_n = 0;
	for (int i = 0; i < es.size(); ++i) {
		e.push_back(make_e(es[i].first, es[i].second, 1));
		max_n = max(max_n, es[i].first);
		max_n = max(max_n, es[i].second);
	}
	g.edges = e;
	max_n++;
	int** m = new int* [max_n];
	for (int i = 0; i < max_n; ++i) {
		m[i] = new int[max_n];
	}
	for (int i = 0; i < max_n; ++i) {
		for (int j = 0; j < max_n; ++j) {
			m[i][j] = INF;
		}
	}
	for (int i = 0; i < e.size(); ++i) {
		m[e[i].from][e[i].to] = e[i].weight;
	}
	g.matrix = m;
	g.e_count = e.size();
	g.v_count = max_n;
	return g;
}

void print_edge(const Edge& e) {
	cout << e.from << "->" << e.to << " w:" << e.weight << endl;
}

void print_graph(const Graph& g, bool is_matrix) {
	if (is_matrix) {
		for (int i = 0; i < g.v_count; ++i) {
			for (int j = 0; j < g.v_count; ++j) {
				cout << setw(10) << g.matrix[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < g.e_count; ++i) {
			print_edge(g.edges[i]);
		}
	}
}
