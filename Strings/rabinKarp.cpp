struct RabinKarp {
private:
    string s;
    int n, base, mod;
    vector<long> p, h;

public:
    RabinKarp(string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = s.size();

        this->base = base;
        this->mod = mod;

        build();
    }

    RabinKarp(int n, string &s, int base = 243, int mod = 1e9 + 7) {
        this->s = s;
        this->n = n;

        this->base = base;
        this->mod = mod;

        build();
    }

    int hash(int l, int r) {
        if (!l) return h[r];
        return (h[r] - ((h[l - 1] * p[r - l + 1]) % mod) + mod) % mod;
    }

private:
    void build() {
        p.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            p[i] = (p[i - 1] * base) % mod;

        h.assign(n, s[0]);
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * base + s[i]) % mod;
    }
};

//ou 

template<class F = unsigned int, class T = string>
struct RabinKarp{
    int n;
    vector<F> p, pw;
    F C[2] = {727, 137};
    RabinKarp(){}
    //change C id for double hashing
    RabinKarp(const T& s, bool id):n((int)s.size()),p(n+1),pw(n+1,1){
        for(int i = 1; i <= n; i++){
            pw[i] = pw[i-1]*C[id];
            p[i] = p[i-1]*C[id] + s[i-1];
        }
    }
    F hash(int i, int len){return p[i+len] - pw[len]*p[i];}
};

//ou 

struct hash_str {
    int p[2] = {727, 137};
    int MOD[2] = {1e9 + 7, 1e9 + 9};

    vector<ll> h[2], pw[2];

    hash_str(string s){
        int n = s.size();

        for(int i = 0; i < 2; i++){
            h[i].resize(n);
            pw[i].resize(n);
        }

        h[0][0] = h[1][0] = s[0];

        for(int i = 1; i < n; i++){
            h[0][i] = (h[0][i - 1]*p[0] + s[i]) % MOD[0];
            h[1][i] = (h[1][i - 1]*p[1] + s[i]) % MOD[1];
        }

        pw[0][0] = pw[1][0] = 1;
        for(int i = 1; i < n; i++){
            pw[0][i] = (pw[0][i - 1]*p[0]) % MOD[0];
            pw[1][i] = (pw[1][i - 1]*p[1]) % MOD[1];
        }
    }

    pair<ll, ll> sub_hash(int l, int r){
        if(l == 0) return make_pair(h[0][r], h[1][r]);

        ll ans_0 = (h[0][r] - h[0][l - 1]*pw[0][r - l + 1]) % MOD[0];
        ll ans_1 = (h[1][r] - h[1][l - 1]*pw[1][r - l + 1]) % MOD[1];

        if(ans_0 < 0) ans_0 += MOD[0];
        if(ans_1 < 0) ans_1 += MOD[1];

        return make_pair(ans_0, ans_1);
    };
};
