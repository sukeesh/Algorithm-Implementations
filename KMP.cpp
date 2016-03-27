/*
    @author Sukeesh
    Knuth Morris Prat Algorithm
*/

ll lps[1000010];

void buildlps(string str){
    lps[0] = 0;
    ll i, j;
    i = 0;
    j = 1;
    while(i<str.sz && j<str.sz){
        if(str[i] == str[j]){
            lps[j] = i + 1;
            j ++;
            i ++;
        }
        else{
            if(i!=0) {
                i = lps[i-1];
            }
            else{
                lps[j] = 0;
                j ++;
            }
        }
        if(j == str.sz){
            break;
        }
    }
}

void kmp(string pattern, string text){
    ll i, j, k;
    memset(lps, 0, sizeof(lps));
    buildlps(pattern);
    i = 0 , j = 0;
    while( i < text.sz ){
        if(pattern[j] == text[i]){
            j++;
            i++;
        }
        if(j == pattern.sz){
            cout << i-j << endl;
            j = lps[j-1];
        }
        else if( i < text.sz && pattern[j] != text[i] ){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    cout << endl;
}