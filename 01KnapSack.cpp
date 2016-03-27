/*
    @author Sukeesh
    0/1 KnapSack Algorithm
*/

ll i, j;

ll KnapSack(ll W, ll n){
	ll dp[n+1][W+1];
	for( i = 0 ; i <= n ; i ++ ){
		for( j = 0 ; j <= W ;j ++ ){
			if(i == 0 || j == 0 ){
				dp[i][j] = 0;
			}
			else if(wt[i-1] <= j){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j])
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][W];
}