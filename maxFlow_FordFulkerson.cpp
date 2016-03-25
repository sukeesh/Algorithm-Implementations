/*
    @author Sukeesh
    MaxFlow Algorithm
*/


/*

    IMPORTANT Define from and to variables and clear memory in every test case!

*/


vector<ll> adj[150];
ll flo[150][150];
ll parent[150];
bool visited[150];
ll from, to, max_flow;

bool bfs(){
    ll node, x;
    queue<ll> Q;
    Q.push(from);
    memset(visited, 0, sizeof(visited));
    visited[from] = true;
    parent[from] = -1;
    while(!Q.empty()){
        node = Q.front();
        Q.pop();
        for(x=0;x<adj[node].size();x++){
            ll nto = adj[node][x];
            if(flo[node][nto] > 0 && visited[nto] == false){
                Q.push(nto);
                parent[nto] = node;
                visited[nto] = true;
            }
        }
    }
    return (visited[to] == true);
}

ll find_min_flow(){
    ll res = INT_MAX, par;
    for(par = to; par != from ; par = parent[par]){
        ll here = parent[par];
        res = min(res, flo[here][par]);
    }
    for(par = to; par != from ; par = parent[par]){
        ll here = parent[par];
        flo[here][par] -= res;
        flo[par][here] += res;
    }
    return res;
}

int main(){
    memset(parent, 0, sizeof(parent));
    max_flow = 0;
    while(bfs()){
        max_flow += find_min_flow();
        memset(parent, 0, sizeof(parent));
    }
    cout << max_flow << endl;
    return 0;
}