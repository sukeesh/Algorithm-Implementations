/*
	@author Sukeesh
	Z Algorithm
*/

ll Zarray[1000010];

void Z(string str){
    memset(Zarray, 0, sizeof(Zarray));
    ll k;
    ll right, left;
    left = 0;
    right = 0;
    for(k = 1 ; k < str.sz ; k ++){
        if(k > right){
            left = right = k;
            while(right < str.sz && str[right] == str[right - left]){
                right ++;
            }
            Zarray[k] = right - left;
            right --;
        }
        else{
            ll k1 = k - left;
            if(Zarray[k1] < right - k + 1){
                Zarray[k] = Zarray[k1];
            }
            else{
                left = k;
                while(right < str.sz && str[right] == str[right - left]){
                    right ++;
                }
                Zarray[k] = right - left;
                right --;
            }
        }
    }
}

void calculateZ(string needle, string haystack){
    ll i;
    string str = needle + "$" + haystack;
    Z(str);
    for(i = 0 ; i < str.sz; i ++){
        if(Zarray[i] == needle.sz){
            cout << i - needle.sz - 1 << endl;
        }
    }
    cout << endl;
}
