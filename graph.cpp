#include "graph.h"

//выделение памяти и возвращение указателя на 2-х мерную квадратную матрицу
int **make_array(unsigned int n) {
    int **ptrary = new int * [n];
    for (int i = 0; i < n; i++) {
        ptrary[i] = new int [n];
    }
    return ptrary;
}

void delete_array(int **arr, unsigned int n) {
    for (int i = 0; i < n; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}

Edge make_e (int _from,int _to,int _weight = 0){
	Edge res;
	res.to=_to;
	res.from = _from;
	res.weight = _weight;
	return res;
}

Graph make_g (int ** m, int n){
	Graph res;
	res.matrix = make_array((unsigned int) n);
	res.v_count=n;
	int s=0;
	int e;
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			res.matrix[i][j]=m[i][j];//
			if(res.matrix[i][j] == 1)
				s++;	
		}
	}
	res.e_count=s;
	res.edges.reserve(res.v_count);
	//построение вектора рёбер через матрицу
	for(int i=0;i<n;i++){
		for(int j=0; j<n; j++){
			if(res.matrix[i][j]!=0){
				res.edges[j].from=i;
				res.edges[j].to=j;
				res.edges[j].weight=res.matrix[i][j];
			}
			
		}
	}
	return res;
}
Graph make_g(const vector<Edge>  &e){// & чтобы не было копирования 
	Graph res;
	res.edges.reserve(e.size());
	set <int> s;
	res.e_count=0;
	for(int i=0;i<e.size();i++){
		
		res.edges[i].from=e[i].from;
		res.edges[i].to=e[i].to;
		res.edges[i].weight=e[i].weight;
		if( (e[i].to!=0)||(e[i].from!=0) )
		res.e_count++;
		s.insert(res.edges[i].to);
		s.insert(res.edges[i].from);
	}
	res.v_count=*s.end();	
	//построение матрицы смежности 
	res.matrix = make_array(res.v_count);
	for(auto i=0;i<=res.v_count;i++){
		for(auto j=1;j<=res.v_count;j++){
			res.matrix[res.edges[i].from][res.edges[i].to]=res.edges[i].weight;
		}
	}
	return res;
}

Graph make_g(const vector <pair<int,int>> & es){

	Graph res;
	res.edges.reserve(es.size());
	res.e_count=0;
	set<int> s;
	
	//Вектор рёбер
	for(auto i=0;i<es.size();i++){
		
		res.edges[i].from=es[i].first;
		res.edges[i].to=es[i].second;
		res.edges[i].weight=1;
		res.e_count++;
		s.insert(res.edges[i].from);
		s.insert(res.edges[i].to);
	}

	res.v_count=*s.end();
	//построение матрицы смежности по парам
	res.matrix = make_array(res.v_count);
	for(auto i=0;i<=res.v_count;i++){
		for(auto j=1;j<=res.v_count;j++){
			res.matrix[res.edges[i].from][res.edges[i].to]=res.edges[i].weight;
		}
	}
		
	return res;	
}

void print_edge(const Edge & e){
	std::cout<<"[ "<<e.from<<" ] "<<"[ "<<e.to<<" ] "<<"[ "<<e.weight<<" ] ";
}

/*bool matrix_adjacency(int**matrix,int n){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if( (i==j)&&(matrix[i][j]!=0) ) return false;
		}
	
	return true;
}*/

void print_graph(const Graph & g, bool is_matrix = true){
	std::cout<<"Количество рёбер "<<g.e_count<<" Количество вершин "<<g.v_count;
	std::cout<<endl;
	if(is_matrix == false )
	for(int i=0;i<g.e_count;i++){

		print_edge(g.edges[i]);
		std::cout<<endl;
	}
	if(is_matrix ==true ) {		
		for(auto i=0;i<g.v_count;i++){
			for(auto j=0;j<g.v_count;j++){
				std::cout<<g.matrix[i][j]<<" ";
			}
			std::cout<<endl;
		}
	}

}
/*
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

int main(){
  if (test_graph2()) cout<<"Test pass!";
  else cout<<"Test fault!";
	
}
//*/
