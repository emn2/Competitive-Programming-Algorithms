#include <bits/stdc++.h>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string texto;
	string repet;

	getline(cin,texto);
	getline(cin,repet);

	vector<int> freq(30,0);

	int p = 0;

	for(int i=0;i<texto.size();i++){
		if(texto[i] == ' ') freq[29]++;
		else freq[texto[i] - 'a']++;
	}

	for(int i=0;i<repet.size();i++){
		if(repet[i] == ' ') freq[29]--;
		else freq[repet[i] - 'a']--;
	}

	if(freq[29] < 0) cout << ' ';

	for(int i=0;i<28;i++){
		if(freq[i] < 0) cout << char(i + 'a');
	}

	cout << endl;
}
