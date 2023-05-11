#include "graph.h"
#include <iostream>

using namespace std;

Edge make_e (int _from, int _to, int _weight){
    Edge new_e;
    new_e.from = _from;
    new_e.to = _to;
    new_e.weight = _weight;
    return new_e;
}

Graph make_g (int ** m, int n){
    Graph new_g;
    new_g.matrix = m;
    new_g.e_count = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (m[i][j] >= 0){
                Edge new_e;
                new_e.from = i + 1;
                new_e.to = j + 1;
                new_e.weight = m[i][j];
                new_g.edges.push_back(new_e);
                new_g.e_count++;
            }
        }
    }
    new_g.v_count = n;
    return new_g;
}

Graph make_g (const vector<Edge>  & es){
    Graph new_g;
    int v_count = 0;

    for (int i = 0; i < es.size(); ++i){
        if (es[i].from > v_count) v_count = es[i].from;
        if (es[i].to > v_count) v_count = es[i].to;
    }
    int **new_m = new int * [v_count];
    for (int i = 0; i < v_count; ++i) {
        new_m[i] = new int [v_count];
        for (int j = 0; j < v_count; ++j) new_m[i][j] = -1;
    }
    for (int i = 0; i < es.size(); ++i) {
        new_m[es[i].from - 1][es[i].to - 1] = es[i].weight;
    }
    new_g.v_count = v_count;
    new_g.e_count = es.size();
    new_g.matrix = new_m;
    new_g.edges = es;
    return new_g;
}

Graph make_g (const vector<pair<int,int>>  & es){
    vector <Edge> e(es.size());
    for (int i = 0; i < es.size(); ++i){
        e[i].from = es[i].first;
        e[i].to = es[i].second;
        e[i].weight = 0;
    }
    return make_g(e);
}
void print_edge (const Edge & e){
    cout << e.from << " -- " << e.to << " (" << e.weight << ")\n";
}
void print_graph(const Graph & g, bool is_matrix){
    if (is_matrix){
        for (int i = 0; i < g.v_count; ++i){
            for (int j = 0; j < g.v_count; ++j){
                if (g.matrix[i][j] > -1) cout << g.matrix[i][j] << ' ';
                else cout << "- ";
            }
            cout << '\n';
        }
    } else {
        for (int i = 0; i < g.e_count; ++i){
            print_edge(g.edges[i]);
        }
    }
}