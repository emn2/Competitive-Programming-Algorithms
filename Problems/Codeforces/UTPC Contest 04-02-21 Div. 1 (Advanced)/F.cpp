#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> ii;

bool cmpX(ii &a, ii &b){
    if(a.first < b.first) return true;
    else if(a.first == b.first){
        if(a.second < b.second) return true;
    }
    return false;
}

bool cmpY(ii &a, ii &b){
    if(a.second < b.second) return true;
    else if(a.second == b.second){
        if(a.first < b.first) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<ii> points;
    vector<ii> p(n);
    map<int, int> coordX;
    map<int, int> coordY;

    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        coordX[p[i].first]++;
        coordY[p[i].second]++;
        points.insert(p[i]);
    }

    sort(p.begin(), p.end(), cmpY);   //ordenar pelo Y

    long long ans = 0;

    //Vou considerar o ponto atual como o ponto A do T (vertical)
    for(int i = 0; i < n; i++){
        int j = i+1;
        int xi = p[i].first;
        int yi = p[i].second;

        while(p[j].second == yi && j < n){

            int xj = p[j].first;
            int yj = p[j].second;

            int diffX = xj - xi;

            if(diffX % 2 == 0 && i != j){
                int xsearch = xi + diffX/2;
                int ysearch = yi;
                if(points.count(make_pair(xsearch, ysearch))){
                    ans += (coordX[xsearch] - 1);
                }
            }

            j++;
        }
    }

    sort(p.begin(), p.end(), cmpX);

    //Vou considerar o ponto atual como o ponto A do T (horizontal)
    for(int i = 0; i < n; i++){
        int j = i+1;
        int xi = p[i].first;
        int yi = p[i].second;

        while(p[j].first == xi && j < n){

            int xj = p[j].first;
            int yj = p[j].second;

            int diffY = yj - yi;

            if(diffY % 2 == 0 && i != j){
                int xsearch = xi;
                int ysearch = yi + diffY/2;
                if(points.count(make_pair(xsearch, ysearch))){
                    ans += (coordY[ysearch] - 1);
                }
            }

            j++;
        }
    }

    cout << ans << '\n';

    return 0;
}
