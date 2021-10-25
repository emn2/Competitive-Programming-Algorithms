#include <bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string op;

	cin >> op;

	int ans;
	cin >> ans;

	bool m = false;
	bool l = false;
	// m;

	vector<int> opr;
	vector<int> aux;

	for(int i=0;i<op.size();i++){
		if(op[i] == '*'){
			opr.push_back(-1);
		}
		else if(op[i] == '+'){
			opr.push_back(-2);
		}
		else{
			opr.push_back(op[i] - 48);
		}
	}

	aux = opr;

	for(int i=1;i<opr.size();i+=2){
		if(opr[i] == -2) continue;
		opr[i+1] *= opr[i-1];
		opr[i-1] = 0;
	}

	int sum = 0;
	for(int i=0;i<opr.size();i+=2){
		sum += opr[i];
	}

	if(sum == ans) m = true;

	opr = aux;

	sum = 0;

	sum = opr[0];

	for(int i=1;i<opr.size();i+=2){
		if(opr[i] == -2){
			sum += opr[i+1];
		}
		else{
			sum *= opr[i+1];
		}
	}

	if(sum == ans) l = true;

	if(l + m == 0) cout << "I" << endl;
	else if(l + m == 2) cout << "U" << endl;
	else if(l) cout << "L" << endl;
	else cout << "M" << endl;
}
