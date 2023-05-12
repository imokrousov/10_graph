#include <iostream>
#include "graph.h"

using namespace std;

int main(){
    string type;
    Graph graph;
    cout << "Vvedite tip grapha:" << endl;
    cin >> type;
    if (type == "edges"){
		int e_count;
        cout << "Vvedite kol-vo reber:" << endl;
		cin >> e_count;
        vector <Edge> edges;
		cout << "Vvedite rebra:" << endl;
        for (int i = 0; i < e_count; i++){
            Edge e;
            cin >> e.from >> e.to >> e.weight;
            edges.push_back(e);
        }
		// cerr << e_count << "es";
        graph = make_g(edges);
    } 
	else if (type == "pairs"){
		int e_count;
        cout << "Vvedite kol-vo par:" << endl;
		cin >> e_count;
        vector<pair<int,int>> pairs(e_count);
		cout << "Vvedite pari:" << endl;
        for (int i = 0; i < e_count; i++){
            cin >> pairs[i].first >> pairs[i].second;
        }
        graph = make_g(pairs);
    }
	else if (type == "matrix"){
		int v_count;
        cout << "Vvedite kol-vo vershin:" << endl;
		cin >> v_count;
        int **m = new int * [v_count];
		cout << "Vvedite matricu:" << endl;
        for (int i = 0; i < v_count; i++) {
            m[i] = new int [v_count];
            for (int j = 0; j < v_count; j++) {
                cin >> m[i][j];
            }
        }
        graph = make_g(m, v_count);
	}
	else {
		cout << "Neverno";
		return 0;
	}
    print_graph(graph, false);
    print_graph(graph);
	return 0;
}