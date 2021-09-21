template <int maxn, int MOD> struct FFTMod {
    constexpr static int lg2(int n) { return 32 - __builtin_clz(n - 1); }
    const static int MAXN = 1 << lg2(maxn);
    typedef complex<double> cpx;
    int rev[MAXN];
    cpx rt[MAXN];
    FFTMod() {
        rt[1] = cpx{1, 0};
        for (int k = 2; k < MAXN; k *= 2) {
            cpx z[] = {1, polar(1.0, M_PI / k)};
            for (int i = k; i < 2 * k; i++)
                rt[i] = rt[i / 2] * z[i & 1];
        }
    }
    void fft(cpx *a, int n) {
        for (int i = 0; i < n; i++)
            rev[i] = (rev[i / 2] | (i & 1) << lg2(n)) / 2;
        for (int i = 0; i < n; i++)
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        for (int k = 1; k < n; k *= 2)
            for (int i = 0; i < n; i += 2 * k)
                for (int j = 0; j < k; j++) {
                    auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
                    cpx z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] += z;
                }
    }

    cpx in[2][MAXN], out[2][MAXN];
    vector<ll> multiply(const vector<int> &a, const vector<int> &b) {
        fill(all(in[0]), cpx{0, 0}), fill(all(in[1]), cpx{0, 0});
        int cut = sqrt(MOD), sz = a.size() + b.size() - 1;
        int n = 1 << lg2(sz);
        vector<ll> res(sz);
        for (int i = 0; i < a.size(); i++)
            in[0][i] = {a[i] / cut, a[i] % cut};
        for (int i = 0; i < b.size(); i++)
            in[1][i] = {b[i] / cut, b[i] % cut};
        fft(in[0], n), fft(in[1], n);
        for (int i = 0; i < n; i++) {
            int j = (n - i) & (n - 1);
            cpx fl = (in[0][i] + conj(in[0][j])) * cpx{0.5, 0}, fs = (in[0][i] - conj(in[0][j])) * cpx{0, -0.5},
                gl = (in[1][i] + conj(in[1][j])) * cpx{0.5, 0}, gs = (in[1][i] - conj(in[1][j])) * cpx{0, -0.5};
            out[0][-i & (n - i)] = (fl * gl) + (fl * gs) * cpx{0, 1};
            out[1][-i & (n - i)] = (fs * gl) + (fs * gs) * cpx{0, 1};
        }
        fft(out[0], n), fft(out[1], n);
        for (int i = 0; i < sz; i++) {
            out[0][i] /= n, out[1][i] /= n;
            ll av = round(out[0][i].real());
            ll bv = round(out[0][i].imag()) + round(out[1][i].real());
            ll cv = round(out[1][i].imag());
            av %= MOD, bv %= MOD, cv %= MOD;
            res[i] = av * cut * cut + bv * cut + cv;
            res[i] = (res[i] % MOD + MOD) % MOD;
        }
        return res;
    }
};
