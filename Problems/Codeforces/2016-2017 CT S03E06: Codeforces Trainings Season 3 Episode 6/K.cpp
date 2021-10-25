#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << setprecision(2) << fixed;

    int vel = 0, hI, minI, segI, totalI;
    double distAcumulada = 0;
    string s;
    while(getline(cin, s)){
        int h, min, seg, total;
        double ans = 0;
        h = stoi(s.substr(0, 2));
        min = stoi(s.substr(3, 2));
        seg = stoi(s.substr(6, 2));
        total = seg + min*60 + h*3600;

        //mudar velocidade
        if(s.size() > 8){
            distAcumulada += vel*(total - totalI)/3600.0;
            vel = stoi(s.substr(9));
            hI = h, minI = min, segI = seg, totalI = total;
        }
        //query
        else{
            if(total >= totalI)
                total -= totalI;
            else                   //virou o dia
                total += 86400 - totalI;
            ans = vel*total/3600.0;
            cout << s << ' ' << ans+distAcumulada << " km\n"; 
        }
    }

    return 0;
}
