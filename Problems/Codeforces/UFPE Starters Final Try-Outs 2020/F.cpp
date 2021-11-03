#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

struct node{
    bool isEnd;
    int x, y, h;
    node(int a, int b, int c, bool e): x(a), y(b), h(c), isEnd(e) {}
};


bool cmp(node &a, node &b){
    if(a.x < b.x) return true;
    else if(a.x == b.x){
        if(a.y < b.y) return true;
        else if(a.y == b.y){
            if(a.isEnd == 0) return true;
            else return false;
        }
        else return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<node> points;

    for(int i = 0; i < n; i++){
        int l, r, h;
        cin >> l >> r >> h;
        points.push_back(node(l, r, h, 0));
        points.push_back(node(r, r, h, 1));
    }

    sort(points.begin(), points.end(), cmp);

    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, 1e9 + 5));
    
    ll ans = 0;
    int last = 0;
    for(int i = 0; i < 2*n; i++){
        while(pq.top().second < points[i].x) pq.pop();

        ans += 1LL*(points[i].x - last)*pq.top().first;

        last = points[i].x;

        if(!points[i].isEnd) pq.push(make_pair(points[i].h, points[i].y));
    }

    cout << ans << '\n';
}
