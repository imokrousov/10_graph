#include <iostream>
#include <set>
#include "graph.h"

using namespace std;

int main()
{
    int** vec;
    int n;
    cin >> n;
    vec = new int*[n];
    for (int i = 0; i < n; i++) vec[i] = new int[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> vec[i][j];
        }
    }
    cout << endl; 
    Graph g = make_g(vec, n);
    print_graph(g, 0);
    cout << endl;
    print_graph(g, 1);
    cout << endl << endl;

/*    
1 2 1
1 3 1
1 4 1
2 1 1
2 3 1
2 5 1
3 1 1
3 2 1
3 4 1
5 2 1
5 4 1*/

/*
0 1 1 1 0
1 0 1 0 1
1 1 0 1 0
0 0 0 0 0
0 1 0 1 0
*/
    
    vector<pair<int, int> > vec2;
    int m;
    cin >> m;
    vec2.resize(m);
    for (int i = 0; i < m; i++){
        int to, from, w;
        cin >> to >> from >> w;
        vec2[i] = make_pair(to-1, from-1);
    }
    cout << endl;
    g = make_g(vec2);
    print_graph(g, 0);
    cout << endl;
    print_graph(g, 1);
    cout << endl << endl;
    
    /**/
    
    vector<Edge> vec3;
    int s;
    cin >> s;
    vec3.resize(s);
    for (int i = 0; i < s; i++){
        int to, from, w;
        cin >> to >> from >> w;
        vec3[i] = make_e(to-1, from-1, w);
    }
    cout << endl;
    g = make_g(vec3);
    print_graph(g, 0);
    cout << endl;
    print_graph(g, 1);
    cout << endl << endl;

    return 0;
}
