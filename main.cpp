//#include <iostream>
#include "graph.h"


using namespace std;


bool test_graph(){
	
	
	int **mat = make_array(3);
	int test_arr [3][3] = {{0, 1, 1},{0, 0, 0},{1, 0, 0}};
	for(auto i=0; i<3;i++)
		for(auto j=0;j<3; j++)
			mat[i][j]=test_arr[i][j];
	Graph graph_1 = make_g(mat,3);
	print_graph(graph_1,0);
	graph_1.matrix[0][0]=1;
	//Graph graph_2 = make_g(mat,4);	
	for(int i=0; i<3;i++)
		for(int j=0;j<3;j++)
			if(graph_1.matrix[i][j] != test_arr[i][j])  return false; 
	if((graph_1.v_count!=3)||(graph_1.e_count!=3)) return false;	
	return true;
	
}


bool test_graph2(){
	
	vector<Edge> v;
	v.reserve(3);
	v.push_back( Edge {1,2,5});
	v.push_back( Edge {1,0,4});
	v.push_back( Edge {0,2,3});
	Graph graph_1 = make_g(v);
	print_graph(graph_1,1);
	for(int i=0; i<3;i++)
		if( (graph_1.edges[i].from != v[i].from)||(graph_1.edges[i].to != v[i].to)||
				(graph_1.edges[i].weight != v[i].weight) ) return false; 
	if((graph_1.v_count!=3)||(graph_1.e_count!=3)) return false;	
	return true;
	
}

bool test_graph3(){
	
	vector<pair<int,int>> v;
	v.reserve(3);
	v.push_back(pair{1,2});
	v.push_back(pair{1,0});
	v.push_back(pair{0,2});
	Graph graph_1 = make_g(v);
	print_graph(graph_1,1);
	for(int i=0; i<3;i++)
		if( (graph_1.edges[i].from != v[i].first)||(graph_1.edges[i].to != v[i].second)||(graph_1.edges[i].weight != 1) ) return false; 
	if((graph_1.v_count!=3)||(graph_1.e_count!=3)) return false;	
	return true;
	
}

int main(){
  if (test_graph2()) cout<<"Test pass!";
  else cout<<"Test fault!";
	
}