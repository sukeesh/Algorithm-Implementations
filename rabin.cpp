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

bool vis[1001010];

ll suk(char ch){
  ll res = int(ch) - int('a') + 1;
  return res;
}

ll hashit(string x){
  ll i, pr = 3;
  ll ct = 0, res = 0;
  for ( i = 0 ; i < x.sz ; i ++ ){
    res += fpow(pr, ct) * suk(x[i]);
    ct ++;
  }
  return res;
}

ll fir(string x, ll m){
  return hashit(x.substr(0, m));
}

void rollinhash(string x, ll m){
  ll i, pr = 3;
  ll here = fir(x, m);
  vis[here] = true;
  for ( i = m ; i < x.sz ; i ++ ){
    here -= suk(x[i-m]);
    here /= pr;
    here += suk(x[i]) * fpow(pr, m-1);
    vis[here] = true;
  }
}

int main(){
    string a, b;
    cin >> a >> b;
    ll hash1 = hashit(b);
    rollinhash(a, b.sz);
    if(vis[hash1])
      cout << " Fuck Yeah!!\n";
    else
      cout << " Nope!\n";
    return 0;
}
