#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define LOCAL
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define loop(i,n,k) for(int i = k; i<n; i++) 
#define loopv(i,v,k) for(int i=k; i<sz(v); i++)
#define f first 
#define s second
#define pb(x) push_back(x);




struct seg_tree{

    // struct data{
        // default constructor !!!!
    // };
    ll n;
    vector<ll>tree;
    vector<ll>lazy;

    seg_tree(ll N) : n(N), tree(4*N), lazy(4*N){}

    ll mrg(ll x, ll y){
        return x + y;
    }


    void build(const vector<ll>& in,ll id, ll ns, ll ne){
        if(ns==ne){
            tree[id] = in[ns];
            return ;
        }
        ll l = 2*id+1;
        ll r = l+1;
        ll md = ns+(ne-ns)/2;
        build(in,l, ns, md);
        build(in,r, md+1, ne);
        tree[id] = mrg(tree[l],tree[r]);
    }

// one_indexed !!!!!!!!

void upd_lazy(ll id ,ll ns, ll ne){
    if(!lazy[id]) return ;
    tree[id]+=lazy[id]*(ne-ns+1);
    if(ns!=ne){
        ll l = 2*id+1;
        ll r = 2*id+2;
        lazy[l]+=lazy[id];
        lazy[r]+=lazy[id];
    }
    lazy[id]=0;
}

void upd(ll qs, ll qe, ll v, ll id , ll ns , ll ne){
    upd_lazy(id, ns, ne);
    if(qs>ne || qe<ns){
        return;
    }
    if(qs<=ns && qe>=ne){
        lazy[id]=v;
        upd_lazy(id, ns, ne);
        return;
    }
    ll l = 2*id+1;
    ll r = 2*id+2;
    ll md = ns+(ne-ns)/2;
    upd(qs, qe, v, l, ns, md);
    upd(qs, qe, v, r, md+1, ne);
    tree[id] = mrg(tree[l],tree[r]);
}

ll query(ll qs, ll qe, ll id, ll ns, ll ne){
    upd_lazy(id, ns, ne);
    if(qs>ne || qe<ns){
        return 0;
    }
    if(qs<=ns && qe>=ne){
        return  tree[id];
    }
    ll l = 2*id+1;
    ll r = 2*id+2;
    ll md = ns+(ne-ns)/2;
    ll v1 = query(qs, qe, l, ns, md);
    ll v2 = query(qs, qe, r, md+1, ne);
    return mrg(v1,v2);
}

void build(vector<ll>& in){
    build(in,0,0,n-1);
}

void update_range(ll qs, ll qe, ll v) {
        upd(qs, qe, v, 0, 0, n - 1);
    }

    
ll range_query(ll qs, ll qe) {
        return query(qs, qe, 0, 0, n - 1);
    }

};

void test_case(){
	
   
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        
        test_case();
		
        
    }
}
