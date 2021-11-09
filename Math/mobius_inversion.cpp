const int MAXN = 1e5 + 5;

vector<bool> isPrime(MAXN, true);
vector<int> u(MAXN, 1);

for(int i = 2; i < MAXN; i++){
    if(isPrime[i]){
        for(int j = i; j < MAXN; j += i){
            if(j > i) isPrime[j] = 0;
            if(j % (i*i) == 0) u[j] = 0;
            u[j] = -u[j];
        }
    }
}
