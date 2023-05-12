#include <iostream>
#include <vector>
#include <iomanip>
#include "graph.h"
Graph create_g(int e_count, int v_count) {
	int** a = new int* [v_count];
	for (int i = 0; i < v_count; ++i) {
		a[i] = new int[v_count];
	}
	for (int i = 0; i < v_count; ++i) {
		for (int j = 0; j < v_count; ++j) {
			a[i][j] = NE;
		}
	}
	Graph res;
	res.matrix = a;
	vector <Edge> edg;
	res.edges = edg;
	res.e_count = e_count; res.v_count = v_count;
	return res;
}
Edge make_e(int _from, int _to, int _weight) {
	Edge res;
	res.from = _from; res.to = _to; res.weight = _weight;
	return res;
}
Graph make_g(int** m, int n) {
	Graph res;
	vector <Edge> edg;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (m[i][j] != NE) {
				Edge e;
				e.from = i;
				e.to = j;
				e.weight = m[i][j];
				edg.push_back(e);
			}
		}
	}
	res = create_g(edg.size(), n);
	res.matrix = m;
	res.edges = edg;
	return res;
}
Graph make_g(const vector<Edge>& edg, int n) {
	Graph res;
	res = create_g(edg.size(), n);
	for (int i = 0; i < edg.size(); ++i) {
		res.matrix[edg[i].from][edg[i].to] = edg[i].weight;
		res.matrix[edg[i].to][edg[i].from] = edg[i].weight;
	}
	res.edges = edg;
	return res;
}
Graph make_g(const vector<pair<int, int>>& vec, int n) { //пусть у каждого ребра вес 1
	vector <Edge> edg;
	for (int i = 0; i < vec.size(); ++i) {
		Edge e;
		e.from = vec[i].first;
		e.to = vec[i].second;
		e.weight = 1;
		edg.push_back(e);
	}
	return make_g(edg, n);
}
void print_edge(const Edge& e) {
	cout << "from: " << e.from << "    to: " << e.to << "    weight: " << e.weight << "\n";
	return;
}
void print_graph(const Graph& g, bool is_matrix) {
	if (is_matrix) {
		for (int i = 0; i < g.v_count; ++i) {
			for (int j = 0; j < g.v_count; ++j) {
				cout << setw(10) << g.matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		for (int i = 0; i < g.e_count; ++i) {
			print_edge(g.edges[i]);
		}
	}
	return;
}