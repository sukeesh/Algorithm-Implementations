#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef vector <long long> vli;
typedef pair< long long ,long long> pli;

#define eps 1e-9
#define all(a)   a.begin(),a.end()
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define sz size()
#define sl(inp) scanf("%lld",&inp)
#define sd(inp) scanf("%d",&inp)
#define rep(i, a, b) for(int i = a; i < b ; ++i)

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int inf = 1e9;
const int N = 1234;

ll fpow(ll base,ll power){
	ll result = 1;
    while (power > 0){
    	if (power%2 == 1){
    		result=(result*base);
    	}
    	base = (base*base);
    	power/=2;
    }
	return result;
}

ll T[N], L[N], P[N], nr, maxn = -1;
vector<ll> adj[N];

ll lca(ll x, ll y){
    while(P[x] != P[y]){
        if(L[x] > L[y]){
            x = P[x];
        }
        else{
            y = P[y];
        }
    }
    while ( x!= y ){
        if ( L[x] > L[y] ){
            x = T[x];
        }
        else{
            y = T[y];
        }
    }
    return x;
}

void dfs1(ll node, ll lvl){
    L[node] = lvl;
    maxn = max(maxn, lvl);
    for ( ll i = 0 ; i < adj[node].sz ; i ++ ){
        ll to = adj[node][i];
        T[to] = node;
        dfs1(to, lvl+1);
    }
}

void dfs(ll node){
    if ( L[node] < nr ){
        P[node] = 1;
    }
    else{
        if( !(L[node] % nr) ){
            P[node] = T[node];
        }
        else{
            P[node] = P[T[node]];
        }
    }
    for (ll k = 0 ; k < adj[node].sz ; k ++ ){
        dfs(adj[node][k]);
    }
}

void refresh(ll x){
    memset(T, 0, sizeof(T));
    memset(L, 0, sizeof(L));
    memset(P, 0, sizeof(P));
    for ( ll i = 0 ; i <= x ; i ++ ){
        adj[i].clear();
    }
}

int main(){
    ll t, id = 1;
    scanf("%d", &t);
    while ( t -- ){
        printf("Case %d:\n", id);
        id ++;
        ll n, i;
        cin >> n;
        refresh(n+1);
        for ( i = 1 ; i <= n ; i ++ ){
            ll m;
            scanf("%d", &m);
            while ( m-- ){
                ll x;
                scanf("%d", &x);
                adj[i].pb(x);
            }
        }
        T[1] = 1;
        dfs1(1, 0);
        nr = sqrt(maxn);
        dfs (1);
        ll q;
        scanf("%d", &q);
        while ( q -- ){
            ll u, v;
            scanf("%d %d", &u, &v);
            printf("%d\n", lca(u,v));
        }
    }
    return 0;
}