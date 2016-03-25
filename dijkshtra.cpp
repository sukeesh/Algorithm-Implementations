/*
    @author Sukeesh
    Dijkshtra Algorithm
*/


#include "bits/stdc++.h"
using namespace std;

#define N 20001
const int inf = 1000000000;

vector< int > adj[N];
int grad[N][N];
int d[N];
int i, n;

inline void pre(){
	for( i = 0 ; i <= n ; i++ ){
		d[i]=inf;
	}
}

inline void dijkstra(int node){
	pre();
	d[node] = 0;
	priority_queue< pair< int, int > > Q;
	Q.push(make_pair(0,node));
	while(!Q.empty()){
		pair< int, int > top = Q.top();
		Q.pop();
		int u = top.second;
		if(top.first>d[u]) continue;
		for(i=0;i< adj[u].size();i++){
			int to = adj[u][i];
			int len = grad[u][to];
			if(d[u] + len < d[to]){
				d[to] = d[u] + len;
				Q.push(make_pair(-d[to],to));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> n >> q ;
	
	for( i = 0 ; i < q ; i++ ){
		int x,y,l;
		cin >> x >> y >> l;
		adj[x].push_back(y); 
		adj[y].push_back(x);
		grad[y][x]=l; 
		grad[x][y]=l;
	}

	dijkstra(0);

	for( i = 0 ; i < n ; i++ ){
		cout << "Shortest Distance from " << 0 << " to " << i << " is " << d[i] << "\n";
	}
}