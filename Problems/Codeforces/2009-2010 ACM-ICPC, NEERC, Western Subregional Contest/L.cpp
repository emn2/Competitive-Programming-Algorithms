#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
const int tam = 1e6 + 5;

struct segment{
    int x, y;
};

segment s[10010];
segment e[10010];

bool compare(segment s, segment e){
    if(s.x == e.x && s.y == e.y) return true;
    return false;
}

bool verify(segment s, segment e, segment ss, segment ee){
    if(compare(s, ss) || compare(s, ee) || compare(e, ss) || compare(e, ee)){
        if( (e.x - s.x)*(ee.x - ss.x) + (e.y - s.y) * (ee.y - ss.y) == 0 ) return true;
        return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen("lshape.in", "r", stdin);
    freopen("lshape.out", "w", stdout);

    int n; cin >> n;

    for(int i = 0;i < n;i++){
        cin >> s[i].x >> s[i].y >> e[i].x >> e[i].y;
    }

    int ans = 0;

    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if( verify(s[i], e[i], s[j], e[j]) ) ans += 1;
        }
    }    

    cout << ans << endl;

    return 0;
}
