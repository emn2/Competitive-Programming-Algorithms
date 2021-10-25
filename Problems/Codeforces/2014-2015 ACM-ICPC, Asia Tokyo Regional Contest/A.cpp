#include <bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;

	cin >> n >> m;

	vector<int> bit;

	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		bit.push_back(a);
	}

	vector<int> run;

	for(int i=0;i<m;i++){
		int a;
		cin >> a;
		run.push_back(a);
	}

	vector<int> ex1, ex2;
	int c = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<run[i];j++){
			ex1.push_back(c);
			ex2.push_back((c+1)%2);
		}
		c = (c+1)%2;
	}

	int mini = 1e9 + 7;

	vector<int> aux = bit;

	int count = 0;
	for(int i=0;i<n;i++){
		if(aux[i] == ex1[i]) continue;
		bool achei = false;
		for(int j=i;j<n;j++){
			if(aux[j] == ex1[i]){
				count += (j - i);
				swap(aux[j], aux[i]);
				achei = true;
				break;
			}
		}

		if(!achei) count = 1e9 + 7;
	}

	mini = min(mini, count);

	aux = bit;

	count= 0;
	for(int i=0;i<n;i++){
		if(aux[i] == ex2[i]) continue;
		bool achei = false;
		for(int j=i;j<n;j++){
			if(aux[j] == ex2[i]){
				count += (j - i);
				swap(aux[j], aux[i]);
				achei = true;
				break;
			}
		}

		if(!achei) count = 1e9 + 7;
	}

	mini = min(mini, count);

	cout << mini << endl;
}
