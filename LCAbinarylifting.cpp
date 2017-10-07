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
#define rd(inp) scanf("%lld",&inp)
#define rd2(inp1, inp2) scanf("%lld %lld",&inp1, &inp2)
#define rl(inp) scanf("%d",&inp)
#define pf(out) printf("%lld\n", out);

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int inf = 1e9;

ll read(){
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus){
		return -result;
	}
	else{
		return result;
	}
}

ll fpow(ll base,ll power){
	ll result = 1;
	while (power > 0){
		if (power%2 == 1) result=(result*base);
  		base = (base*base);
  		power /= 2;
  	}
	return result;
}

#define maxn 10000

ll L[maxn], LCA[maxn][22], lg;

ll getLca(ll x, ll y){
    
    if(L[x] < L[y]){
        swap(x, y);
    }

    for(ll i=lg; i >= 0; i--){
        if( LCA[x][i] != 0 && L[LCA[x][i]] >= L[y] ){
            x = LCA[x][i];
        }
    }
    
    if( x == y ){
        return x;
    }

    for(ll i = lg ; i >= 0 ; i--){
        if( LCA[x][i] != 0 && LCA[x][i] != LCA[y][i] ){
            x = LCA[x][i];
        	y = LCA[y][i];
        }
    }

    return LCA[x][0];
}

void ConstructLCA(ll n){
    lg = ceil(log2(n));
    ll i, j;
    for ( i = 1 ; i <= n ; i ++ ) LCA[i][0] = par[i];

    for ( i = 1 ; i <= lg ; i ++ ) {
        for( j = 1 ; j <= n ; j ++ ) {
            if( LCA[j][i-1] ) {
                LCA[j][i] = LCA[LCA[j][i-1]][i-1];
            }
        }
    }
}

void dfs(ll node, ll par){
	L[node] = L[par] + 1;
	par[node] = par;
	for ( ll j = 0 ; j < adj[node].sz ; j ++ ){
		ll to = adj[node][j];
		if(to != par) dfs(to, node);
	}
}

int main(){
	ll n, m;
  	n = read();
  	m = read();
  	ll i, j;
  	for ( i = 0 ; i < m ; i ++ ){
  		ll u, v;
  		rd2(u, v);
  		adj[u].pb(v);
  		adj[v].pb(u);
  	}
  	dfs(1);
  	ConstructLCA(n);
	return 0;
}
