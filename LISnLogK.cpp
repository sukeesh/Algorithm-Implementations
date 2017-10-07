/*
    @author Sukeesh
    Longest Increasing Subsequence
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
const int N = 1e6 + 5;

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

int n;
int a[32];
int I[32];
vector<int> ret(33);

int main(){
    scanf("%d", &n);
    int i;
    for ( i = 0 ; i < n ; i ++ ){
        scanf("%d", &a[i]);
    }
    I[0] = -inf;
    ret[0] = -inf;
    for ( i = 1 ; i <= n ; i ++ ){
        I[i] = inf;
        ret[i] = inf;
    }
    int LIS = 0;
    for ( i = 0 ; i < n ; i ++ ){
        int low = 0 , high = LIS;
        while ( low <= high ){
            int mid = (low + high) / 2;
            if ( I[mid] < a[i] ){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        I[low] = a[i];
        if ( LIS < low ){
            LIS = low;
            vector<int> new_vec(I + 1, I + low + 1);
            ret.clear();
            ret = new_vec;
        }
    }
    printf ("%d\n", LIS);
    for ( i = 0 ; i  < ret.sz ; i ++ ){
        cout << ret[i] << " " ;
    }
    cout << "\n";
    return 0;
}