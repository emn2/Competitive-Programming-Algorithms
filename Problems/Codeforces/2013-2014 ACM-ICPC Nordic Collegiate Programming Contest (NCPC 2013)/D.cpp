#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const double inf = 1e100, eps = 1e-9;
const double PI = acos(-1.0L);

int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct PT {
  double x, y;
  PT(double x = 0, double y = 0) : x(x), y(y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (double c) const { return PT(x*c, y*c); }
  PT operator / (double c) const { return PT(x/c, y/c); }
  
  bool operator <(const PT &p) const {
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
  }
  bool operator ==(const PT &p) const {
    return !cmp(x, p.x) && !cmp(y, p.y);
  }
  bool operator != (const PT &p) const {
    return !(p == *this);
  }
};

double cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }

vector<PT> convexHull(vector<PT> p, bool needs = 1) {
  if(needs) sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int n = p.size(), k = 0;
  if(n <= 1) return p;
  vector<PT> h(n + 2);
  for(int i = 0; i < n; i++) {
    while(k >= 2 && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) <= 0) k--;
    h[k++] = p[i];
  }
  for(int i = n - 2, t = k + 1; i >= 0; i--) {
    while(k >= t && cross(h[k - 1] - h[k - 2], p[i] - h[k - 2]) <= 0) k--;
    h[k++] = p[i];
  }
  h.resize(k); // n+1 points where the first is equal to the last
  return h;
}

inline int add(int a, int b, int mod){
  int ans = a + b;
  if(ans >= mod)
    ans -= mod;
  return ans;
}

double dist (PT p, PT q) { return hypot(p.x-q.x, p.y-q.y); }

void solve(){
  
  int n;
  cin >> n;

  vector<PT> h(n);
  for(int i = 0; i < n; i++)
    cin >> h[i].x >> h[i].y;
  
  h = convexHull(h);
  h.pop_back();

  n = h.size();
  double ans = 0;
  for(int i = 0; i < n; i++){
    int B = n, A = 0;
    while(B - A > 4){
      int m1 = (A + B) / 2;
      int m2 = (A + B) / 2 + 1;
      int p1 = add(m1, i, n);
      int p2 = add(m2, i, n);
      if(dist(h[p1], h[i]) < dist(h[p2], h[i]))
        A = m1;
      else
        B = m2;
    }
    for(int j = A; j <= B; j++) ans = max(dist(h[add(j, i, n)], h[i]), ans);
  }

  cout << fixed << setprecision(10);
  cout << ans << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	while(tc--)
		solve();
}

