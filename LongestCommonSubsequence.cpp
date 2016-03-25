/*
    @author Sukeesh
    Longest Common Subsequence
*/

string a, b;
cin >> a >> b;
ll dp[a.sz+2][b.sz+2];
memset(dp, 0, sizeof(dp));
ll i, j;
for(i=0;i<a.sz;i++){
    for(j=0;j<b.sz;j++){
        if(a[i]==b[j]){
            dp[i+1][j+1] = dp[i][j] + 1;
        }
        else{
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
}
cout << dp[a.sz][b.sz] << endl;