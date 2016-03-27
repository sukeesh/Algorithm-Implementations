/*
    @author Sukeesh
    Disjoint Set Union
*/

ll Parent[10000], rank[10000], N;

void make_set(){
	for(ll i=1;i<=N;i++){
		Parent[i]=x;
		rank[i]=0;
	}
}

ll find(ll x){	
	if(x!=Parent[x]){
		Parent[x]=find(Parent[x]);
	}
    return Parent[x];
}

void uunion(ll &x,ll &y){
    ll PX=find(x),PY=find(y);
    if(PX==PY){ 
    	return;
    }
    if(rank[PX]>rank[PY]){
        Parent[PY]=PX;
    }
    else{
        Parent[PX]=PY;
        if(rank[PX]==rank[PY]){
            rank[PY]++;
        }
    }
}