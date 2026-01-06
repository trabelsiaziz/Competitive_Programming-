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
#include <functional>
#include <math.h>
#include <ostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

// order_of_key (K): Number of items strictly smaller than K.
// find_by_order(k): Kth element in a Set (counting from zero).


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
#define rall(a) (a).rbegin(), (a).rend()
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



// ************************************************** code *************************************************** 



bool cmp(const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.f < b.f;  
}

void precompute(){
  //do something first !!!
}

const ll inf = 1e18+9; 

vector<pair<ll,ll>>adj[nax]; 
vector<ll> dists(nax,inf); 

vector<ll> par(nax, 0); 
vector<bool>vis(nax);

ll n, m; 
map<pair<ll,ll>,pair<ll,ll>>ed;


void dijks(ll s){
  priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq ; 
  pq.push({0,s}); 
 
  for(int i = 0; i<= n ; i++) {
    dists[i] = 1e18; 
    vis[i] = 0; 
  }
 
  dists[s] = 0; 
  // vis[1] = 1; 
 
  while(!pq.empty()){
 
    auto cur = pq.top(); 
    pq.pop(); 
 
 
    // if(vis[cur.s]) continue;
 
    // vis[cur.s] = 1; 
 
    for(auto x : adj[cur.s]){
      if(dists[x.f] > x.s + cur.f){
        dists[x.f] = cur.f + x.s;
        pq.push({dists[x.f], x.f});
        par[x.f] = cur.s;
      }
      else if(dists[x.f] == x.s + cur.f){
        auto ped = ed[{max(par[x.f],cur.s),min(par[x.f],cur.s)}];
        auto curped = ed[{max(x.f, cur.s),min(x.f,cur.s)}];

        if(ped.s > curped.s) par[x.f] = cur.s;
        
      }
    }
 
  }
}

// you should actually read the stuff at the bottom
void test_case(){
  //write your code here
    
    cin >> n >> m; 

    for(int i = 0 ; i<m; i++){
        ll u, v , w; 
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});  
        ed[{max(u,v),min(u,v)}] = {i+1,w}; 
    }


    ll s; 
    cin >> s; 
    par[s] = s; 
    dijks(s); 


  
    vector<ll>ans;
    ll weight = 0; 
    for(int node=1;node<=n;++node){
        debug() << imie(node) imie(dists[node]) imie(par[node]);
        if(node==s)
        {
            continue;
        }
        ll curr = node; 
        ll pr = par[curr]; 
        pair<ll,ll> pp = {max(pr,curr),min(pr,curr)};
        ans.pb(ed[pp].f); 
        weight += ed[pp].s;
 
    }

    cout << weight << endl; 
    print(ans); 
    cout << endl;   


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
     // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        
        test_case();
    
        
    }
}
