#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define fastio cin.tie(nullptr); ios_base::sync_with_stdio(false)
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long double ld;

const ld EPS = 1e-22L;
int sgn (ld t) { return abs(t) < EPS ? 0 : (t > 0) - (t < 0); }

struct PT {
    ld x, y;
    PT (ld x = 0.0L, ld y = 0.0L) : x(x), y(y) {}
    PT operator- (PT o) { return {x - o.x, y - o.y}; }
    PT operator* (ld t) { return {x*t, y*t}; }
    PT operator/ (ld t) { return {x/t, y/t}; }
    PT operator+ (PT o) { return {x + o.x, y + o.y}; }
};

ld dot (PT u, PT v) { return u.x*v.x + u.y*v.y; }
ld cross (PT u, PT v) { return u.x*v.y - v.x*u.y; }
ld orient (PT a, PT b, PT c) { return cross(b - a, c - a); }
ld abs (PT p) { return hypot(p.x, p.y); } 

struct Line {
    PT v;
    ld c;
    Line (PT v, ld c) : v(v), c(c) {}
    Line (PT a, PT b) : v(b - a), c(cross(v, a)) {}
    ld side (PT p) { return cross(v, p) - c; }
    bool contains (PT p) { return sgn(side(p)) == 0; }
    bool opposes (PT a, PT b) { return sgn(side(a))*sgn(side(b)) < 0; }
    ld dist (PT p) { return abs(side(p))/abs(v); }
    // move.cpp
    void translate(PT u);
    void reverse();
    // orthogonality.cpp
    Line perpThrough(PT p);
    PT proj(PT p);
    PT reflect(PT p);
};

struct Polygon {
    int sides;
    vector<PT> p;
    Polygon (const vector<PT>& v) : p(v), sides(v.size()) {}
    int next (int i) { return i == sides - 1 ? 0 : i + 1; }
    // convexity.cpp
    int convex();
    // area.cpp
    ld shoelace();
    ld area();
    bool ccw();
    bool cw();
    // cut.cpp
    Polygon cut(Line l);
    // contains-point.cpp
    int contains(PT q);
    // largest-circle.cpp
};

ld Polygon::shoelace () {
    ld sum = 0;
    for (int i = 0; i < sides; i++) sum += cross(p[i], p[next(i)]);
    return sum;
}

ld area (PT a, PT b, PT c) { return abs(cross(b - a, c - a))/2.0L; }
// area of a polygon (it may be concave)
ld Polygon::area () { return abs(shoelace())/2.0L; }

// whether vertices are listed counterclockwise
bool Polygon::ccw () { return sgn(shoelace()) > 0; }

// whether vertices are listed clockwise
bool Polygon::cw () { return sgn(shoelace()) < 0; }

PT mid(PT &a, PT &b){
    PT c;
    c.x = (max(a.x, b.x) - min(a.x, b.x))/2.0 + min(a.x, b.x);
    c.y = (max(a.y, b.y) - min(a.y, b.y))/2.0 + min(a.y, b.y);
    return c;
}

int main(){
    fastio;
    int idx = 1;
    while(true){
        bool sim = false;
        vector<PT> points(4);
        for(int i = 0; i < 4; i++){
            cin >> points[i].x >> points[i].y;
            if(points[i].x != 0.0 || points[i].y != 0.0) sim = true;
        }
        
        if(!sim) break;
        
        ld menor_dist = 1e18;
        ld r1, r2;
        
        Polygon tudo(points);
        ld area1, area2, area_total = tudo.area();
        
        vector<PT> novos(8);
        novos[0] = points[0];
        novos[2] = points[1];
        novos[4] = points[2];
        novos[6] = points[3];
        
        //P0, P1, P2, P3, MP0P1(P4), MP1P2(P5), MP2P3(P6), MP0P3(P7)
        novos[1] = mid(points[0], points[1]);
        novos[3] = mid(points[1], points[2]);
        novos[5] = mid(points[2], points[3]);
        novos[7] = mid(points[3], points[0]);
        
        
        for(int i = 0; i < 8; i++){
            vector<PT> agora;
            if(i % 2 == 0){
                for(int j = i + 3; j <= i + 5; j++){
                    for(int k = i; k <= j; k++){
                        if(k == i || k == j) agora.pb(novos[k % 8]);
                        else{
                            if(k % 2 == 0) agora.pb(novos[k%8]);
                        }
                    }
                    Polygon recente(agora);
                    area1 = recente.area();
                    area2 = area_total - area1;
                    if(abs(area2 - area1) < menor_dist){
                        r1 = area1;
                        r2 = area2;
                        menor_dist = abs(area2 - area1);
                    }
                    agora.clear();
                }
            }
        }
        
        vector<PT> t;
    
        int a[4] = {0, 1, 5, 6};
        int b[4] = {0, 2, 3, 7};
        
        for(int i = 0 ; i < 4; i++){
            t.pb(novos[a[i]]);
        }
        
        Polygon p_novo(t);
        area1 = p_novo.area();
        area2 = area_total - area1;
        if(abs(area2 - area1) < menor_dist){
            r1 = area1;
            r2 = area2;
            menor_dist = abs(area2 - area1);
        }
        
        t.clear();
        
        for(int i = 0 ; i < 4; i++){
            t.pb(novos[b[i]]);
        }
        
        Polygon p2_novo(t);
        area1 = p2_novo.area();
        area2 = area_total - area1;
        if(abs(area2 - area1) < menor_dist){
            r1 = area1;
            r2 = area2;
            menor_dist = abs(area2 - area1);
        }
        
        if(r1 > r2) swap(r1, r2);
        printf("Cake %d: %.3Lf %.3Lf\n", idx++, r1, r2);
    }

    return 0;
}
