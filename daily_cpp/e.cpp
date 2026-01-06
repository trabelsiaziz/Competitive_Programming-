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


bool cmp(const pair<ll,ll>& a, const pair<ll,ll>& b){
        return a.f < b.f;  
}

void precompute(){
  //do something first !!!
}

// you should actually read the stuff at the bottom
void test_case(){
	//write your code here
  int n; 
  cin >> n; 
  vector<int>in(n);
  read(in); 

  ld dp[n+1][n+1][n+1];
  // vector<vector<vector<ld>>>dp(n+3,vector<vector<ld>>(n+3,vector<ld>(n+3))); 
  memset(dp, 0, sizeof(dp));

  vector<int>cnt(3); 
  for(int i : in) cnt[i-1]++; 

  dp[cnt[0]][cnt[1]][cnt[2]] = 1; 
  
  for(int c = 0; c<=n ; c++){
    for(int b = 0; b<=n; b++){
      for(int a = 0 ; a<=n ; a++){
        
        dp[a][b][c] += 1; 
        ld po = (ld)(n-a-b-c)/n;
        
        if(a-1 >= 0){
          ld pa = (ld)a / n; 
          dp[a][b][c] += (pa * dp[a-1][b][c]) / (1-po); 
        }
        if(b-1 >= 0){
          ld pb = (ld)b / n; 
          dp[a][b][c] += (pb * dp[a+1][b-1][c]) / (1-po);
        }
        if(c-1 >= 0){
          ld pc = (ld)c / n; 
          dp[a][b][c] += (pc * dp[a][b+1][c-1]) / (1-po);
        }


      }
    }
  }

  // for(auto p : dp) debug() << imie(p);

  cout << dp[0][0][0] << endl; 

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
