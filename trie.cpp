const int LN = 31;
int curr=1;
int lft[LN*upperlimit];
int rgt[LN*upperlimit];
int trie[LN*upperlimit];

void insert(int n){
    int node=1;
    trie[node]++;
    for(int i=LN-1;i>=0;i--){
        int bit=(n>>i)&1;
        if(bit){
            if(!rgt[node])rgt[node]=++curr;
            node=rgt[node];
        }
        else{
            if(!lft[node])lft[node]=++curr;
            node=lft[node];
        }
        trie[node]++;
    }
}

void remove(int n){
    int node=1;
    trie[node]--;
    for(int i=LN-1;i>=0;i--){
        int bit=(n>>i)&1;
        if(bit){
            node=rgt[node];
        }
        else{
            node=lft[node];
        }
        trie[node]--;
    }
}

int query(int n){
    int ret=0;
    int node=1;
    for(int i=LN-1;i>=0;i--){
        int bit=(n>>i)&1;
        if(bit){
            if(lft[node] && trie[lft[node]]){
                node=lft[node];
                ret+=(1<<i);
            }
            else{
                node=rgt[node];
            }
        }
        else{
            if(rgt[node] && trie[rgt[node]]){
                node=rgt[node];
                ret+=(1<<i);
            }
            else{
                node=lft[node];
            }
        }
    }
    return ret;
}