#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int main(){
	
	int b;
	cin >> b;
 
	int cont = 1000;
 
	while(b--){
 
		int x,y;
		ll lim = 1e6;
 
		x = uniform_int_distribution<ll>(0, lim)(rng);
		y = uniform_int_distribution<ll>(0, lim-1)(rng);
 
		cout << x << " " << y << endl;
		cont--;
		ll dist;
		cin >> dist;
 
		if(dist == 0){
			continue;
		}
 
		if(cont == 0){
			assert(false);
		}
 
		cout << x << " " << y+1 << endl;
		ll dist2;
 
		cin >> dist2;
 
		cont--;
 
		if(dist2 == 0){
			continue;
		}
 
		if(cont == 0){
			assert(false);
		}
 
		y = (dist-dist2+1)/2 + y;
 
		if(y < 0 || y > 1e6){
			b++;
			continue;
		}
 
		cout << x << " " << y << endl;
		cin >> dist;
 
		cont--;
		if(dist == 0){
			continue;
		}
 
		if(cont == 0){
			assert(false);
		}
 
		ll dx = sqrt(dist);
		if(dx*dx != dist){
			b++;
			continue;
		}
 
		if(x-dx >= 0){
			cout << x-dx << " " << y << endl;
			cin >> dist;
			cont--;
 
			if(dist == 0){
				continue;
			}
 
			if(cont == 0){
				assert(false);
			}
		}
 
		if(x+dx <= 1e6){
			cout << x+dx << " " << y << endl;
			cin >> dist;
			cont--;
 
			if(dist == 0){
				continue;
			}
 
			if(cont == 0){
				assert(false);
			}
		}
 
		if(y-dx >= 0){
			cout << x << " " << y-dx << endl;
			cin >> dist;
			cont--;
 
			if(dist == 0){
				continue;
			}
 
			if(cont == 0){
				assert(false);
			}
		}
 
		if(y+dx <= 1e6){
			cout << x << " " << y+dx << endl;
			cin >> dist;
			cont--;
 
			if(dist == 0){
				continue;
			}
 
			if(cont == 0){
				assert(false);
			}
		}
 
		b++;
	}
}
