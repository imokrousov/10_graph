#include "graph.h"
#include <vector>
#include <iostream>

using namespace std;

Edge make_e (int _from, int _to, int _weight) {
    Edge ans;
    ans.from = _from;
    ans.to = _to;
    ans.weight = _weight;
    return ans;
}

Graph make_g (int ** m, int n) {
    Graph ans;
    ans.matrix = m;
    ans.v_count = n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] >= 0) {
                count ++;
                ans.edges.push_back(make_e(i, j, m[i][j]));
            }
        }
    }
    ans.e_count = count;
    return ans;
}

Graph make_g (const vector<Edge>  & es) {
    Graph ans;
    ans.edges = es;
    int n = es.size();
        // cerr << n <<"vn";
    ans.e_count = n;
    int v_count = 0;
    for (int i = 0; i < n; i++) {
        v_count = max(es[i].from, v_count);
        v_count = max(es[i].to, v_count);
    }
    ans.v_count = v_count;
    int **m = new int * [v_count];
	for (int i = 0; i < v_count; i++) {
		m[i] = new int[v_count];
	}
    for (int i = 0; i < v_count; i++) {
        for (int j = 0; j < v_count; j++) {
            m[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) m[es[i].from - 1][es[i].to - 1] = es[i].weight;
    ans.matrix = m;
    return ans;
}

Graph make_g (const vector<pair<int,int>>  & es) {
    int n = es.size();
    vector <Edge> eg(n);
    for (int i = 0; i < n; i++) {
        eg[i].from = es[i].first;
        eg[i].to = es[i].second;
        eg[i].weight = 1;
    }
    Graph ans = make_g(eg);
    return ans;
}

void print_edge (const Edge & e) {
    cout << e.from << " -> " << e.to << " potracheno " << e.weight << " elo";
}

void print_graph(const Graph & g, bool is_matrix) {
    if (is_matrix) {
        cout << "Matrix:";
        for (int i = 0; i < g.v_count; i++) cout << "to" << i + 1 << "|";
        cout << endl;
        for (int i = 0; i < g.v_count; i++) {
            cout << "from " << i + 1 << ": ";
            for (int j = 0; j < g.v_count; j++) {
                if (g.matrix[i][j] >= 0 ) cout << g.matrix[i][j] << " | ";
                else cout << "- | ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Edges:" << endl;
        int n = g.e_count;
        //cerr << n;
        for (int i = 0; i < n; i++) {
            print_edge(g.edges[i]);
            cout << endl;
        }
    }
}