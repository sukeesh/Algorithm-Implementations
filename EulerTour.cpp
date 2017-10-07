/*
*
*First let's see the conditions for an undirected graph:
*An undirected graph has an eulerian circuit if and only if it is connected and each vertex has an even degree
*An undirected graph has an eulerian path if and only if it is connected and all vertices except 2 have even degree. 
*One of those 2 vertices that have an odd degree must be the start vertex, and the other one must be the end vertex.
*For a directed graph we have:
*A directed graph has an eulerian circuit if and only if it is connected and each vertex has the same in-degree as out-degree.
*A directed graph has an eulerian path if and only if it is connected and each vertex except 2 have the same in-degree as out-degree, 
*and one of those 2 vertices has out-degree with one greater than in-degree (this is the start vertex),
*and the other vertex has in-degree with one greater than out-degree (this is the end vertex).
*
*/


#include <bits/stdc++.h>

using namespace std;

// Directed Graph!

int edges = 0, cnt[1000], in[1000], out[1000];
vector<int> adj[1000];
vector<int> path;

void dfs(int node){
	for ( ; cnt[node] < adj[node].size() ; ){
		int v = adj[node][cnt[node]];
		cnt[node] ++;
		dfs(v);
	}
	edges++;
	path.push_back(node);
}

int main(){
	int i, j;
	int n;
	cin >> n;
	int m;
	cin >> m;
	for ( i = 0 ; i < m ; i ++ ){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		in[v] ++;
		out[u]++;
	}
	int cnt_out = 0, cnt_in = 0, start = 1; 
	bool f = 0;
	for ( i = 1 ; i <= n ; i ++ ){
		if ( out[i] - in[i] == 1 ){
			cnt_out ++;
			start = i;
		}
		else if ( in[i] - out[i] == 1 ){
			cnt_in ++;
		}
		else if ( in[i] != out[i] ){
			f = 1;
		}
	}
	if ( f || cnt_in + cnt_out > 2 ){
		printf("No Euler Path Exists!");
		return 0;
	}
	dfs(start);
	reverse(path.begin(), path.end());
	printf("Euler Trail Exists!\n");
	for ( i = 0 ; i < path.size() ; i ++ ) cout << path[i] << " ";
}