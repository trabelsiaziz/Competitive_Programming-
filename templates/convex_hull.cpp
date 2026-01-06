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


/* generic point */
struct point {
  double x, y;
};

/* generic line */
/* for a segment, store the rectangle contained between the two points 
  (as in, leftx, rightx, bottomy, topy)
  then use that for comparisons
*/
struct line {
  double m, b;
  double val(double x) {
    return m * x + b;
  }
};

typedef struct line line;

/* get the line between two points */
line between(point pa, point pb) {
  double m = (pb.y - pa.y) / (pb.x - pa.x);
  double b = (pa.y - m * pa.x);
  line s = {m, b};
  return s;
}

/* generic distance */
double dist(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

/* comparison */
const int delta = 1e-15;
bool within(double d1, double d2) {
  return (d1 > d2 - delta) && (d1 < d2 + delta);
}

/* is a point on a line */
bool on(line s, point p) {
  return within(p.y, s.val(p.x));
}


struct convex_hull {
  using TYPE = lld;
  using point = pair<TYPE, TYPE>;
  vector<point> points;
  vector<point> hull_up, hull_down, hull_tot;

  void init() {
    points = hull_up = hull_down = hull_tot = vector<point>();
  }

  void add_point(TYPE a, TYPE b) {
    points.push_back(make_pair(a, b));
  }

  /* sort by x, then y */
  static bool point_comp(point a, point b) {
    return a.f < b.f || (a.f == b.f && a.s < b.s);
  } 

  /*
  -1 - clockwise
  0 - collinear
  1 - counterclockwise
  */
  int orient(point a, point b, point c) {
    TYPE val = a.f * (b.s - c.s) + b.f * (c.s - a.s) + c.f * (a.s - b.s);

    if (val < 0) return -1;
    else if (val > 0) return 1;
    return 0;
  }

  void find_hull() {
    if (points.size() == 1) {
      hull_up = hull_down = hull_tot = points;
      return;
    }
    sort(points.begin(), points.end(), point_comp);

    point p1 = points[0], p2 = points.back();

    hull_up.push_back(p1);
    hull_down.push_back(p1);

    int sz = (int)points.size();
    for (int i = 1; i < sz; i++) { // for including collinear points on hull, invert the four -1/1's (but not in size()); https://cses.fi/paste/bf929923a2560c1f202a29/
      /* end or clockwise */
      if (i == points.size() - 1 || orient(p1, points[i], p2) == -1) {
        /* while not cw */
        while (hull_up.size() >= 2 && orient(hull_up[hull_up.size() - 2], hull_up.back(), points[i]) != -1)
          hull_up.pop_back();
        hull_up.push_back(points[i]);
      }

      /* end or ccw */
      if (i == points.size() - 1 || orient(p1, points[i], p2) == 1) {
        /* while not ccw */
        while (hull_down.size() >= 2 && orient(hull_down[hull_down.size() - 2], hull_down.back(), points[i]) != 1) 
          hull_down.pop_back();
        hull_down.push_back(points[i]);
      }
    }

    for (int i = 0; i < (int)hull_up.size(); i++)     
      hull_tot.push_back(hull_up[i]);
    for (int i = hull_down.size() - 2; i > 0; i--) 
      hull_tot.push_back(hull_down[i]);
  }
};


// you should actually read the stuff at the bottom
void test_case(){
	//write your code here
  

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
