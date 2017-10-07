/*
    @author Sukeesh
    Binary Indexed Trees
*/

void update(ll ix, ll val) {
  while(ix <= n) {
    tree[ix] += val;
    ix += (ix & -ix);
  }
}

ll query(ll ix) {
  ll res = 0;
  while(ix) {
    res += tree[ix];
    ix -= (ix & -ix);
  }
  return res;
}