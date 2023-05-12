#include <vector>

using namespace std;

const int NE = 2e9 + 7;

struct Edge{
	int from,to;
	int weight;
};

struct Graph{
	int ** matrix;
	vector<Edge> edges;
	int e_count, v_count;
};

Graph create_g(int e_count, int v_count);
Edge make_e (int _from, int _to, int _weight = 0 );
Graph make_g (int ** m, int n);
Graph make_g(const vector<Edge>& edg, int n);
Graph make_g(const vector<pair<int, int>>& vec, int n);
void print_edge (const Edge & e);
void print_graph(const Graph & g, bool is_matrix = true);


