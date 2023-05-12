#include "graph.h"
#include <iostream>
#include <set>

using namespace std;

Edge make_e(int _from, int _to, int _weight = 1) {
    Edge temp;
    temp.from = _from;
    temp.to = _to;
    temp.weight = _weight;
    return temp;
}
Graph make_g(int** m, int n) {
    Graph g;
    g.e_count = n;
    g.matrix = m;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (m[i][j] != 0) {
                count++;
                g.edges.push_back(make_e(i, j, m[i][j]));
            }
        }
    }
    g.v_count = count/2;
    return g;
}
Graph make_g(const vector<Edge>& es) {
    Graph g;
    g.v_count = es.size();
    set<int> s;
    int maxx = -1;
    for (auto edge : es) {
        maxx = max(edge.from, edge.to);
    }
    int** new_arr = new int* [maxx + 1];
    for (int i = 0; i <= maxx; i++) {
        new_arr[i] = new int[maxx + 1];
    }
    for (int i = 0; i <= maxx; ++i) {
        for (int j = 0; j <= maxx; ++j) {
            new_arr[i][j] = 0;
        }
    }
    g.matrix = new_arr;
    g.e_count = maxx;
    for (auto edge : es) {
        g.matrix[edge.from][edge.to] = edge.weight;
        g.matrix[edge.to][edge.from] = edge.weight;
    }
    g.edges = es;
    return g;
}
Graph make_g(const vector<pair<int, int>>& es) {
    Graph g;
    int maxx = -1;
    g.v_count = es.size();
    for (auto p : es) {
        g.edges.push_back(make_e(p.first, p.second));
        maxx = max(p.first, p.second);
    }
    int** new_arr = new int* [maxx + 1];
    for (int i = 0; i <= maxx; i++) {
        new_arr[i] = new int[maxx + 1];
    }
    for (int i = 0; i <= maxx; ++i) {
        for (int j = 0; j <= maxx; ++j) {
            new_arr[i][j] = 0;
        }
    }
    g.matrix = new_arr;
    g.e_count = maxx;
    for (auto edge : es) {
        g.matrix[edge.first][edge.second] = 1;
        g.matrix[edge.second][edge.first] = 1;
    }
    
    return g;
}
void print_edge(const Edge& e) {
    cout << "from:" << e.from << " to:" << e.to << " weight:" << e.weight << "\n";

}
void print_graph(const Graph& g, bool is_matrix = true) {
    cout << "V: " << g.e_count << " R: " << g.v_count << "\n";
    if(is_matrix){
        for (int i = 1; i <= g.e_count; ++i) {
            for (int j = 1; j <= g.e_count; ++j) {
                cout << g.matrix[i][j] << " ";
            }
            cout << "\n";
    }
    }else{
        for (auto edge : g.edges) {
            print_edge(edge);
        }
    }
}