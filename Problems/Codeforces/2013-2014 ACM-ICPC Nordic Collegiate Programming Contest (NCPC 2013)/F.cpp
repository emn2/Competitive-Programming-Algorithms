#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

void solve(){
  string ent[5];
  for(int i = 0; i < 5; i++)
    getline(cin, ent[i]);

  string numero[10];
  numero[0] = "**** ** ** ****";
  numero[1] = "  *  *  *  *  *";
  numero[2] = "***  *****  ***";
  numero[3] = "***  ****  ****";
  numero[4] = "* ** ****  *  *";
  numero[5] = "****  ***  ****";
  numero[6] = "****  **** ****";
  numero[7] = "***  *  *  *  *";
  numero[8] = "**** ***** ****";
  numero[9] = "**** ****  ****";
  
  int ans = 0;
  for(int pos = 0; pos < ent[0].size(); pos += 4){
    string temp = "";
    for(int i = 0; i < 5; i++) 
      temp += ent[i].substr(pos, 3);
    bool achou = false;
    for(int i = 0; i < 10; i++) if(temp == numero[i]){
      ans *= 10;
      ans += i;
      achou = true;
    }

    if(!achou){
      cout << "BOOM!!" << endl;
      return;
    }
  }

  if(ans % 6){
    cout << "BOOM!!" << endl;
    return;
  }
  cout << "BEER!!" << endl;
}

int32_t main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int tc = 1;
	while(tc--)
		solve();
}
