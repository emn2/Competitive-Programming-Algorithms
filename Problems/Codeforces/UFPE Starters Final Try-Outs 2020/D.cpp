#include "bits/stdc++.h"
using namespace std;

typedef long double ld;
typedef pair<ld, ld> pld;

int N;
ld X, Y;
vector<ld> radius;
vector<pld> points;
vector<pld> need;

ld euclidean_dist(const pld &p1, const pld &p2){
    ld dx = p1.first - p2.first;
    ld dy = p1.second - p2.second;

    return sqrt(dx*dx + dy*dy);
}

bool check(ld actual_radius){
    for(int i = 0; i < N; i++){
        if(actual_radius >= need[i].first) actual_radius += need[i].second;
        else return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(12) << fixed;

    cin >> N >> X >> Y;

    need.resize(N);
    radius.resize(N);
    points.resize(N);

    for(int i = 0; i < N; i++) 
        cin >> points[i].first >> points[i].second >> radius[i];


    for(int i = 0; i < N; i++){
        ld dist = euclidean_dist(make_pair(X, Y), points[i]) - radius[i];
        need[i] = make_pair(dist, radius[i]);
    }

    sort(need.begin(), need.end());

    ld l = 0, r = 3e9;
    for(int i = 0; i < 100; i++){
        ld mid = (l + r) / 2.0;

        if(check(mid)) r = mid;
        else l = mid;
    }

    cout << l << '\n';
}
