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

#define maxn 1000100
ll lps[maxn];

void Prefix(string str){
	ll i, j, n = str.sz;
	i = 0, j = 1;
	lps[0] = 0;
	while ( i < n && j < n ){
		if ( str[i] == str[j] ){
			lps[j] = i + 1;
			j ++; i ++;
		}
		else{
			if ( i > 0 ){
				i = lps[i-1];
			}
			else{
				lps[j] = 0;
				j ++;
			}
		}
		if ( j == n ) break;
	}
}

int main(){
	string str;
	cin >> str;
	Prefix(str);
	ll i;
	cout << str << "\n";
	for ( i = 0 ; i < str.sz ; i ++ ){
		cout << lps[i] << " ";
	}
	cout << "\n";
	return 0;	
}