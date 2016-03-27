/*
    @author Sukeesh
    Binary Indexed Trees
*/

void set(ll ix, ll val, ll N) {
  while(ix <= N) {
    tree[ix] += val;
    ix += (ix & -ix);
  }
}

ll get(ll ix) {
  ll res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}