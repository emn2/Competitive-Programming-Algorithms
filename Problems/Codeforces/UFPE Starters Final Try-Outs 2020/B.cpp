#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 5;
int BIT[2*maxn] = {}, n;

void update(int pos, int val){
    while(pos <= n){
        BIT[pos] += val;
        pos += (pos & -pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += BIT[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, q, cnt = 1;
    cin >> n >> m >> q;

    vector<string> list;
    map<string, int> mp;
    map<string, int> qntdlit;

    list.push_back("pos");

    for(int i = 0; i < n; i++){
        string bev;
        cin >> bev;
        if(mp[bev] == 0){
            mp[bev] = cnt++;
        }
        list.push_back(bev);
    }

    for(int i = 0; i < m; i++){
        int val;
        string bev;
        cin >> bev >> val;
        qntdlit[bev] = val;
    }

    for(int i = 1; i <= n; i++){
        update(i, qntdlit[list[i]]);
    }

    for(int i = 0; i < q; i++){
        int oper;
        cin >> oper;
        if(oper == 1){ //colocar a bebida na pos x
            int x;
            string bev;
            cin >> x >> bev;
            update(x, qntdlit[bev] - qntdlit[list[x]]);
            list[x] = bev;
        }
        else{
            int l, r, total, tempo;
            cin >> l >> r;
            tempo = (r - l + 1)*30;
            total = query(r) - query(l-1);
            //cout << total << ' ' << tempo << '\n';
            if(total <= tempo)
                cout << "NO\n";
            else 
                cout << "YES\n";
        }
    }

    return 0;
}
