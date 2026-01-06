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


ll gcd(ll a , ll b) {
    return b ? gcd(b , a % b) : a ;
}
ll lcm(ll a , ll b) {
    return (a * b) / gcd(a , b);
}

ll add(ll a, ll b){
    return (a + b) % mod;
}
ll sub(ll a, ll b){
    return (a - b + mod) % mod;
}
ll mul(ll a, ll b){
    return (((ll)a%mod) * ((ll)b%mod)) % mod;
}

ll powmod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

ll expo(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}


vector<ll> sieve(int n) {
  int*arr = new int[n + 1](); vector<ll> vect;
  for (int i = 2; i <= n; i++)if (arr[i] == 0) {
    vect.push_back(i); 
    for (int j = 2 * i; j <= n; j += i)
      arr[j] = 1;
  }
  return vect;
}



void sieve(){ // time complexity = n*log(log(n)) 
    ll n;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

//******************************spf**********************

int spf[nax];
void computeSPF() {
    for (ll i = 0; i < nax; i++) spf[i] = i; 

    for (ll i = 2; i * i < nax; i++) {
        if (spf[i] == i) {  
            for (ll j = i * i; j < nax; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getPrimeFactors(int x) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}


ll pw(ll a, ll b){
  if(b == 0) return 1;
  ll res = 1;
  for(ll i = 0; i<b ; i++){
    res *= a;
  }
  return res ;
}

vector<pair<ll,ll>>fac(ll n){
  vector<pair<ll,ll>>res;
  if(n%2 == 0){
    int count = 0;
    while(n%2==0){
      count++;
      n/=2;
    }
    res.pb({2,count});
  }
  for(ll i = 3; i * i <= n; i+=2){
    if(n%i == 0){
      res.pb({i,0});
      while(n%i == 0){
        res.back().s++;
        n/=i;
      }
    }
  }
  if(n>1) res.pb({n,1});
  return res;
}


ll fact[nax];
ll inv[nax];



void factorial() {
    fact[0] = 1;
    for (ll i = 1; i < nax; ++i)
        fact[i] = (fact[i - 1] * 1LL * i) % mod;
 
    inv[nax - 1] = powmod(fact[nax - 1], mod - 2);
    for (ll i = nax - 2; i >= 0; --i)
        inv[i] = (inv[i + 1] * 1LL * (i + 1)) % mod;
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    ll res = (fact[n] * 1LL * inv[r]) % mod;
    res = (res * 1LL * inv[n - r]) % mod;
    return res;
}



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
