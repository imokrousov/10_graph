#include "graph.h"

using namespace std;

Edge make_e(int _from, int _to, int _weight) {
  return Edge{_from, _to, _weight};
}
Graph make_g(int **m, int n) {
  Graph g;
  vector<Edge> _edges;
  int x = n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x; j++) {
      if (m[i][j])
        _edges.push_back(make_e(i, j, m[i][j]));
    }
    x--;
  }

  return Graph{m, _edges, int(_edges.size()), n};
}
Graph make_g(const vector<Edge> &es) {
  int n = 0;
  for (int i = 0; i < es.size(); i++) {
    n = max(max(es[i].from, es[i].to), n);
  }
  n++;
  int **m = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    m[i] = (int *)malloc(n * sizeof(int));
  //cout << n << " " << es.size() << endl;
  for (int i = 0; i < es.size(); i++) {
    //cout << es[i].from << " " << es[i].to << endl;
    m[es[i].from][es[i].to] = es[i].weight;
  }
  int e_count = es.size();
  return Graph{m, es, e_count, n};
}
Graph make_g(const vector<pair<int, int>> &es) {
  vector<Edge> _es;
  for (int i = 0; i < es.size(); i++)
    _es.push_back(make_e(es[i].first, es[i].second, 1));
  return make_g(_es);
}
void print_edge(const Edge &e) {
  cout << "From: " << e.from << "; To: " << e.to << "; Weight: " << e.weight
       << endl;
}
void print_graph(const Graph &g, bool is_matrix) {
  if (is_matrix) {
    for (int i = 0; i < g.v_count; i++) {
      for (int j = 0; j < g.v_count; j++) {
        cout << g.matrix[i][j] << " ";
      }
       cout <<endl;
    }
    return;
  }
  for(int i =0 ; i < g.e_count; i++) print_edge(g.edges[i]);
}
