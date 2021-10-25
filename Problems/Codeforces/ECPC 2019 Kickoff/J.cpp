#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  
    #ifdef ONLINE_JUDGE
    freopen("abc.in", "r", stdin); 
    #endif
  
    int n; 
    cin >> n;
  
    vector<int>freq(3,0);
  
    string s; 
    cin >> s;
  
    for(int i = 0; i < n; i++){
        freq[s[i]-'a']++;
    }
  
    bool flag=1;
    if(freq[1]==0 && (freq[0]>0 && freq[2]>0)){
        cout<<"-1"<<endl;
    } else if(freq[0]==0 || freq[2]==0){
        cout<<"0"<<endl;
    } else{
        string sOrd= s;
        int resp=10000000;
        sort(sOrd.begin(), sOrd.end());
        int cnt =0;
        for(int i = 0; i < n; i++){
            if(s[i]!= sOrd[i]){
                cnt++;
            }
        }
        resp = min(resp, (cnt+1)/2);
        reverse(sOrd.begin(), sOrd.end());
        cnt =0;
        for(int i = 0; i < n; i++){
            if(s[i]!= sOrd[i]){
                cnt++;
            }
        }
        resp = min(resp, (cnt+1)/2);
        cout<<resp<<endl;
    }
    return 0;
}
