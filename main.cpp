#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    int n;
    string t;
    cout << "m/e/p:\n";
    cin >> t;        
    cin >> n;
    Graph graph;

    if (t == "m") {
        int** new_m = new int* [n];
        for (int i = 0; i < n; ++i) {
            new_m[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                cin >> new_m[i][j];
            }
        }
        graph = make_g(new_m, n);

        cout << endl;
        print_graph(graph);
        cout << endl;
        for (int i = 0; i < graph.e_count; i++) print_edge(graph.edges[i]);
    }

    else if (t == "e") {
        vector <Edge> edges;
        for (int i = 0; i < n; ++i) {
            int from, to, weight;
            cin >> from >> to >> weight;
            Edge new_e = make_e(from, to, weight);
            edges.push_back(new_e);
        }
        graph = make_g(edges);

        cout << endl;
        print_graph(graph, false);
        cout << endl;
        for (int i = 0; i < graph.e_count; i++) print_edge(graph.edges[i]);
    }

    else if (t == "p") {
        vector <pair<int, int>> edges(n);
        for (int i = 0; i < n; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        graph = make_g(edges);

        cout << endl;
        print_graph(graph, false);
        cout << endl;
        for (int i = 0; i < graph.e_count; i++) print_edge(graph.edges[i]);
    }
}