#include "bits/stdc++.h"

using namespace std;

#define N 100000
vector<int> graph[N], rgraph[N];
stack<int> S;
bool visited[N];

inline void pre()
{
	memset(visited,0,sizeof(visited));
}

inline void fillOrder(int node)
{
	visited[node]=true;
	for(int i = 0 ; i < graph[node].size(); i++ )
	{
		if(!visited[graph[node][i]])
		{
			fillOrder(graph[node][i]);
		}
	}
	S.push(node);
}


inline void rdfs(int node)
{
	visited[node]=true;
	cout << node << " ";
	for(int i=0;i<rgraph[node].size();i++)
	{
		if(!visited[rgraph[node][i]])
		{
			rdfs(rgraph[node][i]);
		}
	}
}

int main()
{
	int i,j;
	int vertices;
	cin >> vertices;
	int edges;
	cin >> edges;
	for(i=0;i<edges;i++)
	{
		int u,v;
		// directed from  u->v 
		cin >> u >> v;
		graph[u].push_back(v);
		rgraph[v].push_back(u);
	}
	pre();
	for(i=1;i<=vertices;i++)
	{
		if(visited[i]==false)
		{
			fillOrder(i);
		}	
	}
	pre();
	while(!S.empty())
	{
		int v=S.top();
		S.pop();
		if(visited[v]==false)
		{
			rdfs(v);
			cout << "\n";
		}
	}
	return 0;
}
