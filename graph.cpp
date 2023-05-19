#include "graph.h"
#include <iostream>

Edge make_e(int _from, int _to, int _weight) {
    Edge edge;
    edge.from = _from;
    edge.to = _to;
    edge.weight = _weight;
    return edge;
}

Graph make_g (int ** m, int n) {
    int edges_count = 0;
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j]) edges_count++; 
        }
    }
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j]) {
				edges.push_back(make_e(i, j, m[i][j]));
			}
		}
	}
    return Graph{m, edges, edges_count/2, n};
}

Graph make_g(const vector<Edge> & es) {
    Graph graph;
    graph.edges = es;
    int n = 0;
    for(int i = 0; i < es.size(); i++) {
        n = max(max(es[i].from, es[i].to), n);
    }
    n++;
    int** m = new int*[n];
    graph.e_count = es.size();
    graph.v_count = n;
    for(int i = 0; i < n; i++) {
        m[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }
    for(auto i: es) {
        m[i.from][i.to] = i.weight;
    }
    graph.matrix = m;
    return graph;
}

Graph make_g(const vector<pair<int, int>> & es) {
    vector<Edge> edges;
    for(int i = 0; i < es.size(); i++) {
        edges.push_back(make_e(es[i].first, es[i].second));
    }
    return make_g(edges);
}

void print_edge ( const Edge & e) {
    cout << e.from << " -> " << e.to << " weight: " << e.weight << endl;
}

void print_graph(const Graph & g, bool is_matrix) {
    if (is_matrix) {
        for (int i = 0; i < g.v_count; i++) {
            for (int j = 0; j < g.v_count; j++) {
                cout << g.matrix[i][j] << ' ';
            }
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < g.e_count; i++) 
            print_edge(g.edges[i]);
    }
}
