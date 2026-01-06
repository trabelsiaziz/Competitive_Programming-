/*
 * One Day or Day One. You Decide!
 * The Universe is under no obligation to make sense to you!
 * Man cannot discover new oceans unless he has the courage 
   to lose sight of the shore.
 * Not all those who wander are lost.
 * 
 *           وما انتفاعُ أخي الدُّنيا بناظرِه  إذا استَوَت عندَهُ الأنوارُ والظُّلَمُ 

 */

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <vector>


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
#define int ll 
// #define int __int128
#define popcount(x) __builtin_popcountll(x) 


const int mod = 1e9 + 7;
const int nax = 2e5 + 5;


bool cmp(const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.f < b.f;  
}

ll floor_div(ll x, ll y) {
  assert(y != 0);
  if (y < 0) {
    y = -y;
    x = -x;
  }
  if (x >= 0) return x / y;
  return (x + 1) / y - 1;
}

ll ceil_div(ll x, ll y) {
  assert(y != 0);
  if (y < 0) {
    y = -y;
    x = -x;
  }
  if (x <= 0) return x / y;
  return (x - 1) / y + 1;
}

template<typename T>
T sqr(T x) {
  return x * x;
}

void precompute(){
  //do something first !!!
}

// you should actually read the stuff at the bottom
void test_case(){
	//write your code here
  int n, m, q; 
  cin >> n >> m >> q; 
  vector<vector<arr<bool, 2>>>emp(m, vector<arr<bool,2>>(7*n));
  for(auto& v : emp){
    for(auto& x : v){
      x[0] = true;
      x[1] = true;
    }
  }  

  for(auto& v : emp){
    for(int i = 5 ; i<7*n ; i += 7){
      v[i][0] = v[i][1] = 0; 
    }
    for(int i = 6 ; i<7*n ; i += 7){
      v[i][0] = v[i][1] = 0; 
    }
  }


  while (q--) {
    int ty; 
    cin >> ty; 
    if(ty == 1){
      int x, a; 
      cin >> a >> x; 
      --x; 
      --a; 
      emp[a][x][0] = false;
      emp[a][x][1] = false;
    }
    else if(ty == 2){
      int a, x, y; 
      cin >> a >> x >> y; 
      --a;
      --x; 
      --y; 
      emp[a][x][y] = false; 
    }
    else{
      int a, b, x, t; 
      cin >> a >> b >> x >> t; 
      --a;
      --b;
      --x; 
      int ans = -1; 
      for(int i = x; i < 7*n ; i++){
        if(emp[a][i][0] == emp[b][i][0] and emp[a][i][0] == true){
          t -= 4; 
          if(t == 0){
            ans = i+1; 
            break; 
          }
        }
        if(emp[a][i][1] == emp[b][i][1] and emp[a][i][1] == true){
          t -= 4; 
          if(t == 0){
            ans = i+1;
            break; 
          }
        }
      }
      cout << ans << endl;
    }


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
  * in case of gdb : g++ -g -O0 -o a a.cpp
  * Beware endl in interaction  

*/



int32_t main() {
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
