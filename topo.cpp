#include "bits/stdc++.h"

using namespace std;

#define N 10000

vector<int> graph[N], topo;
bool visited[N];
stack<int> S;

inline void dfs(int node)
{
	visited[node]=true;
	if(graph[node].size()==0)
	{
		S.push(node);
		return;
	}
	for(int i=0;i<graph[node].size();i++)
	{
		int v=graph[node][i];
		if(!visited[v])
		{
			dfs(v);
		}
	}
	bool nomore=false;
	for(int i=0;i<graph[node].size();i++)
	{
		int v=graph[node][i];
		if(visited[v]==false)
		{
			nomore=1;
		}
	}
	if(!nomore)
	{
		S.push(node);
	}
}

int main()
{
	int vertices,edges,i,j;
	cin >> vertices;
	cin >> edges;
	for(i=0;i < edges;i++)
	{
		// directed from u->v
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	memset(visited,0,sizeof(visited));
	for(i=1;i <= vertices;i++)
	{
		if(visited[i]==false)
		{
			dfs(i);
		}
	}
	
	while(!S.empty())
	{
		topo.push_back(S.top());
		S.pop();	
	}
	for(i=topo.size()-1;i >=0 ;i--)
	{
		cout << topo[i] << " "; 
	}
	cout << "\n";
	return 0;
}
