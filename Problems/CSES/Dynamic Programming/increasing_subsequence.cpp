#include "bits/stdc++.h"
using namespace std;
#define int long long
 
vector<int> v;
 
int solve(){
    vector<int> stack;
    
    for(int i = 0; i < v.size(); i++){
		  vector<int>::iterator it = lower_bound(stack.begin(), stack.end(), v[i]);
		  if(it == stack.end()) stack.push_back(v[i]);
		  else *it = v[i];
	}
	return stack.size();
}
 
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
 
    cout << solve() << endl;
 
    return 0;
}
