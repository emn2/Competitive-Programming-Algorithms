#define int long long

int N, MOD;
int fact[MAXN], fact_inv[MAXN], inv[MAXN];

void pre_calc(){
    inv[1] = 1;
    fact[0] = 1;
    fact_inv[0] = 1;

    for(int i = 2; i < MAXN; i++){
        inv[i] = (MOD - MOD/i) * inv[MOD % i] % MOD;
    }

    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i - 1]*i) % MOD;
        fact_inv[i] = fact_inv[i-1]*inv[i] % MOD;
    }
}

int comb(int n, int k){
    if(n < 0 || k < 0 || k > n) return 0;
    return ((fact[n] * fact_inv[k]) % MOD * fact_inv[n - k] + MOD) % MOD;
}
