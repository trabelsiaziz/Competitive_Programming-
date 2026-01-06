#include <bits/stdc++.h>

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


const int mx=5e5;

int n,m,k,x,y;
vector<int> adj[mx];
vector<int>a ,comp;
bool vis[mx] = {false};

void dfs(int j ){
	vis[j] = true;
	comp.push_back(j);
	for(int e:adj[j]){
		if (!vis[e]){
		dfs ( e );
	}
}
}

void test_case(){
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		cin>>k;
		for(int j = 1; j<k+1 ; j++){
			cin>>x;	
			a.pb(x);
		}
		for(int j = 0; j<k-1 ; j++){
			adj[a[j]].push_back(a[j+1]);
			adj[a[j+1]].pb(a[j]);
		}
		
		a.clear();
	}
	
	for(int i = 1; i<n+1; i++){
		comp.clear(); 
	    fill(vis, vis + n + 1, false);
		dfs(i);
		debug() << imie(comp );
		int ans = comp.size();
		cout<<ans<<' ';
	}
		
		
	
			
		
   
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
