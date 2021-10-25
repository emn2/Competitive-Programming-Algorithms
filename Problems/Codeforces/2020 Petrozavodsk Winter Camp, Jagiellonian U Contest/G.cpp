#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
typedef long long int ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define ALL(x) x.begin(), x.end()

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct PT {
    ll x, y;
    PT (ll x = 0, ll y = 0) : x(x), y(y) {}
    PT operator- (const PT& o) const { return {x - o.x, y - o.y}; }

    // vector space
    PT operator+ (const PT& o) const { return {x + o.x, y + o.y}; }
    PT operator* (ll k) const { return {k*x, k*y}; }

    // products
    ll operator* (const PT& o) const { return x*o.x + y*o.y; }
    ll operator% (const PT& o) const { return x*o.y - y*o.x; }

    // sorting
    bool operator< (const PT& o) const { return x == o.x ? y < o.y : x < o.x; }
    bool operator== (const PT& o) const { return x == o.x && y == o.y; }
};

bool diag (PT a, PT b, PT p) {
    auto [l, r] = minmax(a.x, b.x);
    auto [d, u] = minmax(a.y, b.y);
    return l <= p.x && p.x <= r && d <= p.y && p.y <= u;
}

bool intersect (PT a, PT b, PT c, PT d) {
    PT u = b - a, v = d - c;
    ll ca = v % (a - c), cb = v % (b - c), cc = u % (c - a), cd = u % (d - a);
    return ca*cb < 0 && cc*cd < 0
    || ca == 0 && diag(c, d, a) || cb == 0 && diag(c, d, b)
    || cc == 0 && diag(a, b, c) || cd == 0 && diag(a, b, d);
}

vector<pair<PT, PT>> segments;

void removeIntersections() {
    int n = segments.size();
    while(true) {
        bool found = false;

        for(int i = 0; i < n; ++i) {
            auto &cur = segments[i];
            for(int j = i + 1; j < n; ++j) {
                auto &other = segments[j];
                if(intersect(cur.F, cur.S, other.F, other.S)) {
                    found = true;
                    swap(cur.S, other.S);
                    break;
                }
            }
            if(found) break;
        }

        if(!found) break;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int cases;
    cin >> cases;

    while(cases--) {
        int n;
        cin >> n;

        vector<PT> tables, rooms;
        int x, y;
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            tables.emplace_back(x, y);
        }
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            rooms.emplace_back(x, y);
        }

        for(int i = 0; i < n; ++i) {
            segments.PB({tables[i], rooms[i]});
            removeIntersections();
        }

        for(auto i: segments) {
            cout << 2 << endl;
            cout << i.F.x << " " << i.F.y << endl;
            cout << i.S.x << " " << i.S.y << endl;
        }

        segments.clear();
    }

    return 0;
}
