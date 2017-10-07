#define maxn 10000

ll Parent[maxn], rankk[maxn];

void make_set(){
	for(ll i=0;i<maxn;i++){
		Parent[i]=i;
		rankk[i]=0;
	}
}

ll find(ll x){	
	if(x!=Parent[x]){
		Parent[x]=find(Parent[x]);
	}
    return Parent[x];
}

void uunion(ll x,ll y){
    ll PX=find(x),PY=find(y);
    if(PX==PY){ 
    	return;
    }
    if(rankk[PX]>rankk[PY]){
        Parent[PY]=PX;
    }
    else{
        Parent[PX]=PY;
        if(rankk[PX]==rankk[PY]){
            rankk[PY]++;
        }
    }
}