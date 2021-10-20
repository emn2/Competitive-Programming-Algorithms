#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const int m = 2;
const int MOD = 1e6;

ll n, k, l;
class Matrix{
    public:
        ll mat[m][m];
        void init(){
            mat[0][0] = k; mat[0][1] = 1;
            mat[1][0] = l; mat[1][1] = 0;
        }
        Matrix operator * (const Matrix &p){
            Matrix ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++)
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k]%MOD) * (p.mat[k][j]%MOD)) % MOD;
            return ans;
        }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            ans.mat[i][j] = (i == j);

    while(b){
        if(b&1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    ll ans;
    cin >> n >> k >> l;
    n /= 5;

    if(n == 1){
        ans = (k % MOD);
        cout << setfill('0') << setw(6) << ans;
    }
    else if(n == 2){
        ans = (((k % MOD)*(k % MOD) + l) % MOD);
        cout << setfill('0') << setw(6) << ans;
    }
    else{
        Matrix A;
        A.init();
        A = fexp(A, n);
        ans = A.mat[0][0] % MOD;
        cout << setfill('0') << setw(6) << ans;
    }

    return 0;
}
