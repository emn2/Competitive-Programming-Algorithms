long long fexp(long long base, long long exp, long long mod){
    long long ans = 1;
    while(exp > 0){
        if(exp & 1){
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long a, b, r;
        scanf("%lld %lld", &a, &b);
        r = fexp(a, b, 1e9+7);
        printf("%lld\n", r);
    }

    return 0;
}
