#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define eps 1e-9
#define all(a)   a.begin(),a.end()
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define sz size()
#define sl(inp) scanf("%lld",&inp)
#define sd(inp) scanf("%d",&inp)

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int inf = 1e9;

ll fpow(ll base,ll power){
  ll result = 1;
  while (power > 0){
    if (power%2 == 1) result=(result*base);
  	base = (base*base);
  	power /= 2;
  }
return result;
}

vector<int> adj[100010];
int timer = 1;
int E [100010];
int Eidx[100101];
pair<int,int> L[100101];
pair<int,int> tree[100101];

void build(ll node, ll start, ll end){
	if(start == end){
		tree[node] = mp(L[start].F, start);
	}
	else{
		ll mid = (start + end) / 2;
		build( 2* node , start, mid);
		build( 2* node + 1, mid + 1, end);
		if ( tree[node*2].F < tree[node*2+1].F ){
			tree[node] = tree[node*2];
		}
		else{
			tree[node] = tree[node*2+1];
		}
	}
}

pair<int,int> query(ll node, ll start, ll end, ll l, ll r){
	if(r < start || end < l){
		return mp(inf, 0);
	}
	if(l <= start && end <=r){
		return tree[node];
	}
	ll mid = (start + end) / 2;
	pair<int,int> p1 = query(2 * node, start, mid, l, r);
	pair<int,int> p2 = query(2 * node + 1, mid + 1, end, l, r);
	if ( p1.F < p2.F ){
		return p1;
	}
	else{
		return p2;
	}
}

void dfs(int node, int par, int lvl){
	E[timer++] = node;
	Eidx[node] = timer - 1; 
	L[timer-1] = mp(lvl, node);
	for ( int j = 0 ; j < adj[node].sz ; j ++ ){
		int top = adj[node][j];
		if(top != par)
			dfs(top, node, lvl + 1);
	}
	if ( par != -1 ){
		E[timer++] = par;
		L[timer-1] = mp(lvl - 1, par);
	}
}

int lca(int u, int v){
	u = Eidx[u];
	v = Eidx[v];
	int ans = E[query(1, 1, timer-1, u, v).S];
	return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++ ){
    	int u, v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(1, -1, 0);
    build(1, 1, timer-1);
   // lca queries !!
   int q;
   cin >> q;
   while ( q -- ){
  		int u, v;
  		cin >> u >> v;
  		cout << lca(u, v) << "\n";
   }
   cout << endl;
    return 0;
}