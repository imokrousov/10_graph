#include <iostream>
#include "graph.h"

using namespace std;

int main(){
    int n;
    string type;
    Graph graph;
    cout << "Enter input type (matrix/edges/pairs):\n";
    cin >> type;
    cout << "Enter vertex count:\n";
    cin >> n;
    //cout << "Enter matrix:\n";
    if (type == "edges"){
        cout << "Enter edges - {from} {to} {weight}:\n";
        vector <Edge> edges;
        for (int i = 0; i < n; ++i){
            Edge new_e;
            cin >> new_e.from >> new_e.to >> new_e.weight;
            edges.push_back(new_e);
        }
        graph = make_g(edges);
    } else if (type == "matrix"){
        cout << "Enter matrix: \n";
        int **new_m = new int * [n];
        for (int i = 0; i < n; ++i) {
            new_m[i] = new int [n];
            for (int j = 0; j < n; ++j) {
                cin >> new_m[i][j];
            }
        }
        graph = make_g(new_m, n);
    } else if (type == "pairs"){
        cout << "Enter pairs - {from} {to}:\n";
        vector <pair<int, int>> edges(n);
        for (int i = 0; i < n; ++i){
            cin >> edges[i].first >> edges[i].second;
        }
        graph = make_g(edges);
    }
    cout << "Matrix:\n";
    print_graph(graph);
    cout << "Edges:\n";
    print_graph(graph, false);
}