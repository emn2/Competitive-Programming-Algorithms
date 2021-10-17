#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	vector<ll> grafo[5];
	ll antes[5] = {};
    for(int i=0;i<5;i++){
		string a;
		cin >> a;
		ll o = a[0]-'A', d = a[2]-'A';
		if(a[1]=='>') {
			grafo[d].push_back(o);
			antes[o]++;
		}else{
			grafo[o].push_back(d);
			antes[d]++;
		}
	}
	vector<ll> q;
	for(ll a=0;a<5;a++){
		for(ll i=0;i<5;i++){
			if(antes[i]==0){
				q.push_back(i);
				ll tam = grafo[i].size();
				for(ll j=0;j<tam;j++){
					antes[grafo[i][j]]--;
				}
				antes[i] = -1;
			}
		}
	}
	ll tam = q.size();
	if(tam < 5) printf("impossible\n");
	else{
		for(ll i=0;i<5;i++){
			char c = q[i] + 'A';
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}
