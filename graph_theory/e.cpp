struct SGT{
    struct item
    {
        ll zeros,ones;
        item():zeros((ll)0),ones((ll)0){};
    };
    ll n;
    vector<item> tree;
    vll lazy;
    SGT(ll size) : n(size), tree(4 * size), lazy(4 * size) {}
    void build(const vll &data,string &s, ll node, ll start, ll end) {
        if (start == end) {
            if(s[start]=='1') tree[node].ones^=data[start];
            else tree[node].zeros^=data[start];
        } else {
            ll mid = (start + end) / 2;
            build(data,s, 2 * node, start, mid);
            build(data,s, 2 * node + 1, mid + 1, end);
            tree[node].ones= tree[2 * node].ones^tree[2 * node + 1].ones;
            tree[node].zeros= tree[2 * node].zeros^tree[2 * node + 1].zeros;
        }
    }
    void push(ll node, ll start, ll end) {
        if (lazy[node] != 0) {
            swap(tree[node].ones,tree[node].zeros);
            if (start != end) {
                lazy[2 * node] ^= lazy[node];
                lazy[2 * node + 1]^= lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void updateRange(ll l, ll r, ll value, ll node, ll start, ll end) {
        push(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] ^=value;
            push(node, start, end);
            return;
        }
        ll mid = (start + end) / 2;
        updateRange(l, r, value, 2 * node, start, mid);
        updateRange(l, r, value, 2 * node + 1, mid + 1, end);
         tree[node].ones= tree[2 * node].ones^tree[2 * node + 1].ones;
         tree[node].zeros= tree[2 * node].zeros^tree[2 * node + 1].zeros;
    }
    ll query(ll l, ll r, ll node, ll start, ll end,ll t) {
        push(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) {
           if(t==0) return tree[node].zeros;
           else return tree[node].ones;
        }
        ll mid = (start + end) / 2;
        return query(l, r, 2 * node, start, mid,t)^query(l, r, 2 * node + 1, mid + 1, end,t);
    }
    void updateRange(ll l, ll r, ll value) {
        updateRange(l, r, value, 1, 0, n - 1);
    }
    ll query(ll l, ll r,ll t) {
        return query(l, r, 1, 0, n - 1,t);
    }
    void build(const vll &data,string&s) {
        build(data,s, 1, 0, n - 1);
    }
};

void sol() 
{
  ll n;cin>>n;
  vll a(n);
  lire(a);
  string s;cin>>s;
  SGT tr(n);
  tr.build(a,s);
  ll q;cin>>q;
  while (q--)
  {
    ll t;cin>>t;
    if(t==1){
       ll a,b;cin>>a>>b;
       a--;b--;
       tr.updateRange(a,b,1);
    }else{
       ll type;cin>>type;
       cout<<tr.query(0,n-1,type)<<" ";
    }
  }
  cout<<endl;
}