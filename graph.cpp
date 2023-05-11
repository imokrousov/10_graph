#include "graph.h"
#include <iostream>

using namespace std;


Edge make_e(int _from, int _to, int _weight) {
	Edge res;
	res.from = _from;
	res.to = _to;
	res.weight = _weight;
	return res;
};

Graph make_g(int** m, int n) {
	Graph res;
	res.v_count = n;
	res.matrix = m;
	int _e_count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res.matrix[i][j] >= 1) _e_count++;
		}
	}
	res.e_count = _e_count;
	res.edges.resize(res.e_count);
	int ind = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res.matrix[i][j] >= 1) {
				res.edges[ind] = make_e(i, j, res.matrix[i][j]);
				ind++;
			}
		}
	}
	return res;
}

Graph make_g(const vector<Edge>& es) {
	Graph res;
	res.edges = es;
	int size_matrix = 0;
	for (auto i : es) {
		int n = max(i.to, i.from);
		size_matrix = max(size_matrix, n);
	}
	size_matrix++;
	res.v_count = size_matrix;
	res.e_count = es.size();
	int** m = new int* [size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		m[i] = new int[size_matrix];
	}
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++) {
			m[i][j] = 0;
		}
	}
	for (auto i : es) {
		m[i.from][i.to] = i.weight;
	}
	res.matrix = m;
	return res;
}

Graph make_g(const vector<pair<int, int>>& es) {
	Graph res;
	int size_matrix = 0;
	vector <Edge> vec_edges;
	for (auto i : es) {
		int n = max(i.first, i.second);
		size_matrix = max(size_matrix, n);
		vec_edges.push_back(make_e(i.first, i.second));
	}
	size_matrix++;
	res.edges = vec_edges;
	for (auto i : res.edges) print_edge(i);
	res.v_count = size_matrix;
	res.e_count = es.size();

	int** m = new int* [size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		m[i] = new int[size_matrix];
	}
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++) {
			m[i][j] = 0;
		}
	}
	for (auto i : es) {
		m[i.first][i.second] = 1;
	}
	res.matrix = m;
	return res;
}


void print_edge(const Edge& e) {
	cout << "from:  " << e.from << "    to:  " << e.to << "    weight:  " << e.weight << endl;
};

void print_graph(const Graph& g, bool is_matrix) {
	if (is_matrix) {
		for (int i = 0; i < g.v_count; ++i) {
			for (int j = 0; j < g.v_count; ++j) {
				cout << g.matrix[i][j] << ' ';
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