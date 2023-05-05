#include <vector>
#include <set>
#include <iostream>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H

struct Edge{
	int from,to;
	int weight;
};

struct Graph{
	int ** matrix;
	vector<Edge> edges;
	int e_count, v_count;
};
int **make_array(unsigned int);
void delete_array(int **, unsigned int);
Edge make_e (int , int , int  );
Graph make_g (int ** , int );
Graph make_g (const vector<Edge>  & );
Graph make_g (const vector<pair<int,int>>  & );
void print_edge (const Edge & );
void print_graph(const Graph & , bool );

#endif 
