#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

#define N 10005
#define white 0
#define grey 1
#define black 2

vector<int> adj[N];
vector<int> topo;

int color[N];
bool cycle;

void dfs(int node) {
	color[node] = grey;
	sort(adj[node].begin(), adj[node].end());
	for (int i = adj[node].size() - 1 ; i >= 0 ; i --) {
		int to = adj[node][i];
		if (color[to] == white) {
			dfs(to);
		}
		else if (color[to] == grey) {
			cycle = true;
			return;
		}
	}
	color[node] = black;
	topo.push_back(node);
}

int main() {
	cycle = false;

	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 0 ; i < edges ; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}

	for (int i = nodes ; i >= 1 ; i --){
		if (color[i] == white) {
			dfs(i);
		}
	}

	if (cycle) {
		return 0 * printf("Sandro fails.");
	}
	
	for (int i = topo.size() - 1 ; i >= 0 ; i --) {
		cout << topo[i] << " ";
	}
	return 0;
}
