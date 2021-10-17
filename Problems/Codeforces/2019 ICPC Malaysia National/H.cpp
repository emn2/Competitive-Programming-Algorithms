#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld eps = 1e-8;
const ld PI = acosl(-1);

struct PT {

	ld x, y;
	PT(ld x = 0, ld y = 0): x(x), y(y) {}

	PT operator + (const PT P){
		return PT(x + P.x, y + P.y);}
	PT operator - (const PT P){
		return PT(x-P.x, y-P.y);}

	PT operator * (const ld d){
		return PT(x*d, y*d);}
	PT operator / (const ld d){
		return PT(x/d, y/d);}

	ld operator * (const PT P){
		return x*P.x + y*P.y;}
	ld operator ^ (const PT P){
		return x*P.y - y*P.x;}

	bool operator < (const PT &P){
		if(fabs(x-P.x)<eps) return y < P.y;
		return x < P.x;}
	bool operator == (const PT &P){
		return (*this-P).dist() < eps;}

	ld dist(){
		return sqrt(x*x+y*y);}
	ld angle(){
		ld a = atan2l(y, x);
		if(a<0) a += 2*PI;
		return a;}

	PT normalize(){
		return *this/dist();}
	PT rotateCCW(ld t = PI/2){
    	return PT(x*cosl(t)-y*sinl(t), x*sinl(t)+y*cosl(t));}
	PT rotateCW(ld t = PI/2){
		return rotateCCW(2*PI-t);}

	// Reta AB gira CW ou CCW para ficar na direção de (x,y)
	bool cw(PT a, PT b){
		return ((*this-a)^(b-a)) < -eps;}
	bool ccw(PT a, PT b){
		return ((*this-a)^(b-a)) > eps;}
	bool aligned(PT a, PT b){
		return fabs((*this-a)^(b-a)) < eps;}
};

void convex_hull(vector<PT> &v) {

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	vector<PT> up, down;

	for(PT p: v){

		while(up.size()>=2 && !p.cw(up[up.size()-2], up.back()))
			up.pop_back();

		while(down.size()>=2 && !p.ccw(down[down.size()-2], down.back()))
			down.pop_back();

		up.push_back(p);
		down.push_back(p);
	}

	v.clear();
	v = up;
	for(int i=down.size()-2; i>0; i--) v.push_back(down[i]);
}

bool pointInLine(PT a, PT b, PT c){
	return fabs((b-a)^(c-a)) < eps;
}

bool pointInSegment(PT a, PT b, PT c){
	if(a == b) return a == c;
	bool x = min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x);
	bool y = min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
	return x && y && pointInLine(a, b, c);
}

bool pointInsideTriangle(PT &p, PT &a, PT &b, PT &c){
	if(pointInSegment(a,b,p)) return 1;
	if(pointInSegment(b,c,p)) return 1;
	if(pointInSegment(c,a,p)) return 1;
	bool A = p.cw(a, b), B = p.cw(b, c), C = p.cw(c, a);
	return A == B && A == C;
}

bool pointStriclyInConvexPolygon(vector<PT> &p, PT &q){

	if(p.size() < 3) return 0;

	if(pointInSegment(p[0], p[1], q)) return 0;
	if(pointInSegment(p[0],p.back(), q)) return 0;
	if(q.ccw(p[0], p[1])) return 0;
	if(q.cw(p[0], p.back())) return 0;

	int l = 1, m, r = p.size()-1;
	while(l<r-1){
		m = (l+r)>>1;
		if(!q.cw(p[0], p[m])) r = m;
		else l = m;
	}
	if(pointInSegment(p[l],p[r],q)) return 0;
	return pointInsideTriangle(q, p[0], p[l], p[r]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ncasos;
    cin >> ncasos;
    
    for(int caso=1; caso<=ncasos; caso++){
        printf("Case %d\n", caso);
        
        int npoly, npts;
        cin >> npoly >> npts;
        
        vector<PT> pts(npoly);
        for(int i=0; i<npoly; i++)
            cin >> pts[i].x >> pts[i].y;
            
        convex_hull(pts);
        
        for(int i=0; i<pts.size(); i++)
            printf("%.0Lf %.0Lf\n", pts[i].x, pts[i].y);
        printf("%.0Lf %.0Lf\n", pts[0].x, pts[0].y);
        
        PT p;
        while(npts--){
            cin >> p.x >> p.y;
            printf("%.0Lf %.0Lf ", p.x, p.y);
            if(pointStriclyInConvexPolygon(pts, p)) printf("is unsafe!\n");
            else printf("is safe!\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
