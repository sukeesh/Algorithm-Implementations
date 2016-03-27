/*
	@author Sukeesh
	Segment Tree Implementation
*/


void build(ll node, ll start, ll end){
	if(start == end){
		tree[node] = arr[start];
	}
	else{
		ll mid = (start + end) / 2;
		build( 2* node , start, mid);
		build( 2* node + 1, mid + 1, end);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
}

void update(ll node , ll start, ll end, ll idx, ll val){
	if(start == end){
		arr[idx] += val;
		tree[idx] += val;
	}
	else{
		ll mid = (start + end) / 2;
		if(start <= idx && idx <= mid){
			update(2*node, start, mid, idx, val);
		}
		else{
			update(2*node + 1, mid + 1, end, idx, val);
		}
		tree[node] = tree[node*2] + tree[2*node+1];
	}
}

ll query(ll node, ll start, ll end, ll l, ll r){
	if(r < start || end < l){
		return 0;
	}
	if(l <= start && end <=r){
		return tree[node];
	}
	ll mid = (start + end) / 2;
	ll p1 = query(2 * node, start, mid, l, r);
	ll p2 = query(2 * node + 1, mid + 1, end, l, r);
	return p1 + p2;
}

// Updating an interval ( No Lazy Propagation )

void updateRange(ll node, ll end, ll l, ll r, ll val){
	if(start > end || start > r || end < l){
		return;
	}
	if(start == end){
		tree[node] += val;
		return;
	}
	ll mid = (start + end) / 2;
	updateRange(node * 2, start, mid, l, r, val);
	updateRange(node * 2 + 1, mid + 1, end, l, r, val);

	tree[node] = tree[node*2] + tree[node*2+1];
}

// Lazy 

void updateRange(ll node, ll start, ll end, ll l, ll r, ll val){
	if(lazy[node] != 0){
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l){
		return;
	}
	if(start >= l && end <= r){
		tree[node] += (end - start + 1) * val;
		if(start != end){
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}
	ll mid = (start + end) / 2;
	updateRange(node*2, start, mid, l, r, val);
	updateRange(node*2+1, mid+1, end, l, r, val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll queryRange(ll node, ll start, ll end, ll l, ll r){
	if(start > end || start > r || end < l){
		return 0;
	}
	if(lazy[node] != 0){
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start >= l && end <= r){
		return tree[node];
	}
	ll mid = (start + end) / 2;
	ll p1 = queryRange(node * 2, start, mid, l, r);
	ll p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
	return (p1 + p2);
}