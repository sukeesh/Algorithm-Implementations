ll a[100100], table[100010][20];
const int k =16;

ll func(ll x, ll y){
	return ll(x, y);
}

inline void pre(){
	memset(a, 0, sizeof(a));
	memset(table, 0, sizeof(table));
}

ll query(ll L, ll R, ll n){
	if(L<0 || L>n-1){
		return 0;
	}
	if(R<0 || R>n-1){
		return 0;
	}
	ll ans = 0, ll L1 = L;
	for(ll i = k; i>=0; i--){
		if(L1+(1<<i)-1<=R){
			ans = (func(ans, table[L1][i]));
			L1 += 1<<i;
		}
	}
	return ans;
}

inline void build_sparse(ll n){
	ll i, j;
	for(j=0;j<n;j++){
		table[j][0] = a[j];
	}
	for(j=1; j<=k ;j++ ){
		for(i=0; i<=n-(1<<j) ;i++){
			table[i][j] = (func(table[i][j-1], table[i+(1<<(j-1))][j-1]));
		}
	}
}
