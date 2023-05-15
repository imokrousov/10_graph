#include "graph.h"
#include <set>
#include <iostream>

using namespace std;

Edge make_e (int _from, int _to, int _weight ){
    Edge res;
    res.to = _to;
    res.from = _from;
    res.weight = _weight;
    return res;
}

void print_edge (const Edge & e){
    cout << e.from + 1 << " " << e.to + 1 << " " << e.weight << endl;
}

Graph make_g (int ** m, int n){
    Graph res;
    res.e_count = 0;
    res.v_count = n;
    res.matrix = new int*[n];
    for (int i = 0; i < n; i++) res.matrix[i] = new int[n];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res.matrix[i][j] = m[i][j];
            if (m[i][j] != 0){
                Edge eg;
                eg.from = i; eg.to = j; eg.weight = m[i][j];
                res.edges.push_back(eg);
                res.e_count += 1;
            }
        }
    }
    return res;
}

Graph make_g (const vector<Edge>  & es){
    Graph res;
    res.e_count = es.size();
    res.v_count = 0;
    res.edges.resize(es.size());
    set<int> st;
    for (int i = 0; i < es.size(); i++){
        res.edges[i] = es[i];
        st.insert(es[i].to);
        st.insert(es[i].from);
    }
    res.v_count = st.size();
    int n = res.v_count;
    res.matrix = new int*[n];
    for (int i = 0; i < n; i++) res.matrix[i] = new int[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) res.matrix[i][j] = 0;
    }
    for (int i = 0; i < es.size(); i++){
        res.matrix[es[i].from][es[i].to] = es[i].weight;
    }

    return res;
}

Graph make_g (const vector<pair<int,int>>  & es){
    Graph res;
    res.e_count = es.size();
    res.v_count = 0;
    res.edges.resize(es.size());
    set<int> st;
    for (int i = 0; i < es.size(); i++){
        Edge t;
        t.to = es[i].second; t.from = es[i].first; t.weight = 1;
        res.edges[i] = t;
        st.insert(es[i].first);
        st.insert(es[i].second);
    }
    res.v_count = st.size();
    int n = res.v_count;
    res.matrix = new int*[n];
    for (int i = 0; i < n; i++) res.matrix[i] = new int[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) res.matrix[i][j] = 0;
    }
    for (int i = 0; i < es.size(); i++){
        res.matrix[es[i].first][es[i].second] = 1;
    }
    return res;
}

void print_graph(const Graph & g, bool is_matrix){
    if (is_matrix){
        for (int i = 0; i < g.v_count; i++){
            for (int j = 0; j < g.v_count; j++){
                cout << g.matrix[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        for (int i = 0; i < g.e_count; i++){
            print_edge(g.edges[i]);
        }
    }
}
