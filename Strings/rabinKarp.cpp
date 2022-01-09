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
