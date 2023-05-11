#include "graph.h"

int ** make_matrix(int n) {
    int **buf = new int * [n];
    for (int i = 0; i < n; i++) {
        buf[i] = new int [n];
    }
    return buf;
}

Edge make_e (int _from, int _to, int _weight ){
    Edge e; 
    e.from = _from;
    e.to = _to;
    e.weight = _weight;
    return e;
}

Graph make_g (int ** m, int n){
    Graph g;
    g.matrix = m;
    g.edges = vector <Edge>();
    g.v_count = n;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (m[i][j] != 0){
                g.edges.push_back(make_e(i, j));
            }
        }
    }
    g.e_count = g.edges.size();
    return g;
}

Graph make_g (const vector<Edge>  & es){
    Graph g;
    g.edges = es;
    g.e_count = g.edges.size();
    set <int> st; 
    for (int i = 0; i < g.e_count; ++i){
        st.insert(g.edges[i].from);
    }
    g.v_count = st.size();
    int ** m = make_matrix(g.v_count);
    for (int i = 0; i < g.e_count; ++i){
        m[g.edges[i].from][g.edges[i].to] = g.edges[i].weight;
    }
    return g;
}

Graph make_g (const vector<pair<int,int>>  & es){
    Graph g; 
    set <int> st; 
    g.edges = vector <Edge>();
    for (int i = 0; i < es.size(); ++i){
        st.insert(es[i].first);
        g.edges.push_back(make_e(es[i].first, es[i].second));
        g.e_count++;
    }
    g.v_count = st.size();
    int **m = make_matrix(g.v_count);
    for (int i = 0; i < g.e_count; ++i){
        m[g.edges[i].from][g.edges[i].to] = g.edges[i].weight;
    }
    return g;
}

void print_edge (const Edge & e){
    cout << e.from << ' ' << e.to << ' ' << e.weight << '\n';
}

void print_graph(const Graph & g, bool is_matrix){
    if (is_matrix){
        for (int i = 0; i < g.v_count; ++i){
            for (int j = 0; j < g.v_count; ++j){
                cout << g.matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else{
        for (int i = 0; i < g.e_count; ++i){
            print_edge(g.edges[i]);
        }
    }
}

