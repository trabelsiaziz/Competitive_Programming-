/*
 * One Day or Day One. You Decide!
 * The Universe is under no obligation to make sense to you!
 * Man cannot discover new oceans unless he has the courage 
   to lose sight of the shore.
 * Not all those who wander are lost.
 * 
 *           وما انتفاعُ أخي الدُّنيا بناظرِه  إذا استَوَت عندَهُ الأنوارُ والظُّلَمُ 

 */

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <cstring>
#include <math.h>
#include <ostream>
#include <string>
#include <vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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


#define arr array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define f first 
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n' 
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
#define read(v) for (auto &u : v) cin >> u;
#define print(v) for (auto u : v) cout << u << ' ';

const int mod = 1e9 + 7;
const int nax = 2e5 + 5;


bool cmp(const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.f < b.f;  
}

void precompute(){
  //do something first !!!
}

vector<int>in;


struct seg_tree{

    struct node{
      char H,L; 
      int pH,pL; 
      bool val;
      node() : H('a'), L('a'),pH(0),pL(0), val(false){}
      node(char a, char b, int c, int d, bool k) : H(a), L(b), pH(c),pL(d) ,val(k){}

    };
    ll n;
    vector<node>tree;

    seg_tree(ll N) : n(N), tree(4*N){}

    node mrg(node l, node r){
        node ret;
        ret.L = l.L; 
        ret.H = r.H;
        ret.pH = r.pH;
        ret.pL = l.pL; 
        ret.val = l.val and r.val;
        debug() << imie(in[l.pH]) imie(l.H) imie(in[r.pL]) imie(r.L);
        if(in[l.pH] > in[r.pL]){
          if(l.H == 'L' and r.L == 'R') ret.val = false;
        }
 
        return ret;
    }


    void build(const string& s,ll id, ll ns, ll ne){
        if(ns==ne){
            tree[id] = node(s[ns],s[ns],ns,ns,true);
            return ;
        }
        ll l = 2*id+1;
        ll r = l+1;
        ll md = ns+(ne-ns)/2;
        build(s,l, ns, md);
        build(s,r, md+1, ne);
        tree[id] = mrg(tree[l],tree[r]);
    }



void upd(string& s , ll pos , ll id, ll ns,ll ne){
    if(ns>pos || pos>ne){
        return;
    }
    if(ns==ne){
        char nw_char = (tree[id].H == 'R' ? 'L' : 'R');
        tree[id] = node(nw_char,nw_char,ns,ns,true);
        return ;
    }
    ll l = 2*id+1;
    ll r = l+1;
    ll md = ns+(ne-ns)/2;
    upd(s,pos, l, ns, md);
    upd(s,pos,  r, md+1, ne);
    tree[id] = mrg(tree[l],tree[r]);
}

// point query !! 

node query(ll pos, ll id, ll ns, ll ne){
   
    if(ns==ne){
        return tree[id];
    }
    ll l = 2*id+1;
    ll r = 2*id+2;
    ll md = ns+(ne-ns)/2;
    if(pos <= md) return query(pos,l,ns,md);
    else return query(pos,r,md+1,ne);
 }


// ll query(ll qs, ll qe, ll id, ll ns, ll ne){
//     if(ns>qe || qs>ne){
//         return 1e18; ///infnity
//     }
//     if(qs<=ns && qe>=ne){
//         return tree[id];
//     }
//     ll l = 2*id+1;
//     ll r = l+1;
//     ll md = ns+(ne-ns)/2;
//     return mrg(query(qs, qe, l, ns, md), query(qs, qe,r, md+1,ne));
// }

void build(string& in){
    build(in,0,0,n-1);
}
void update(string& s, ll pos) {
        upd(s,pos, 0, 0, n - 1);
    }

    
bool query(ll pos) {
        node ans = query(pos, 0, 0, n - 1);
        return ans.val;
    }

};



// you should actually read the stuff at the bottom
void test_case(){
	//write your code here
  int n, q; 
  cin >> n >> q; 
  in.resize(n);
  read(in);
  string s; 
  cin >> s; 

  debug() << imie(in) imie(s);

  seg_tree sg(n);
  sg.build(s);

  while(q--){
    int h; 
    cin >> h; 
    sg.update(s,--h);
    debug() << imie(s);

    bool ans = sg.query(0);
    cout << (ans? "YES" : "NO") << endl; 
  }


}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized  
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* by REFERENCE or by VALUE that's the question ?!!!!
	* recursive ??? beware MEMORY LEAK
*/



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(15);
    // precompute();
    int tc = 1;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        
        test_case();
		
        
    }
}
