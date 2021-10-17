#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--){

		priority_queue<ii> pq;
		string x;

		cin >> x;

		int count = 0;

		int n = x.size();

		for(int i=0;i<n;i++){
			if(x[i] == 'B') count--;
			else count++;

			pq.push({count, i});
		}

		int best = -1;

		int past = 0;

		for(int i=0;i<n;i++){

			while(!pq.empty() && pq.top().second < i){
				pq.pop();
			}

			if(pq.top().first - past <= 0){
				best = i;
				break;
			}

			past += (x[i] == 'B'?-1:1);

			pq.push({count + past, i+n});
		}

		cout << best << endl;
	}
}
