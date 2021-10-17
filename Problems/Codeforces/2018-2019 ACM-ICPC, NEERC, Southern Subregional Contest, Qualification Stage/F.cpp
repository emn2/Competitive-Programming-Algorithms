#include <bits/stdc++.h>
using namespace std;

#define long long long int

const int MAX_INIT = 999;
const int MAX_SUM = 27;
const int MAX_LEN = 3;

int sum_digits(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt_sum[MAX_LEN + 1][MAX_SUM + 1] = {0};
    for (int i = 0; i < 10; i++)
        cnt_sum[1][i] = 1;
    
    for (int i = 2; i <= MAX_LEN; i++)
        for (int j = 0; j <= MAX_SUM; j++)
            for (int k = 0; k <= min(j, 9); k++)
                cnt_sum[i][j] += cnt_sum[i - 1][j - k];

    int cnt_init[MAX_INIT + 1][MAX_SUM + 1];
    for (int i = 0; i <= MAX_INIT; i++) {
        int s = sum_digits(i);
        cnt_init[0][s]++;
    }

    for (int i = 1; i <= MAX_INIT; i++) {
        for (int j = 0; j <= MAX_SUM; j++) {
            cnt_init[i][j] = cnt_init[i - 1][j];

            int s = sum_digits(i);

            int want = s + j;
            if (want >= 0 && want <= MAX_SUM)
                cnt_init[i][j] += cnt_sum[3][want];

            if (j) {
                want = s - j;
                if (want >= 0 && want <= MAX_SUM)
                    cnt_init[i][j] += cnt_sum[3][want];
            }
        }
    }

    int n; 
    cin >> n;
    while (n--) {
        int t; cin >> t;
        if (!t) cout << "0\n";
        else {
            int init = t / 1000, end = t % 1000;
            int s = abs(sum_digits(init) - sum_digits(end));

            int ans = 0;
            if (init)
                for (int i = 0; i < s; i++)
                    ans += cnt_init[init - 1][i];

            int init_sum = sum_digits(init), pow = 100, end_sum = 0;
            for (int i = 2; i > 0; i--) {
                int limit = (t / pow) % 10;
                for (int j = 0; j < limit; j++)
                    for (int k = 0; k < s; k++) {
                        int want = init_sum + k - end_sum - j;
                        if (want >= 0 && want <= MAX_SUM)
                            ans += cnt_sum[i][want];

                        if (k) {
                            want = init_sum - k - end_sum - j;
                            if (want >= 0 && want <= MAX_SUM)
                                ans += cnt_sum[i][want];
                        }
                    }

                pow /= 10;
                end_sum += limit;
            }

            int limit = t % 10;
            for (int i = 0; i < limit; i++)
                for (int j = 0; j < s; j++) {
                    int want = init_sum + j - end_sum - i;
                    if (!want) ans++;

                    if (j) {
                        want = init_sum - j - end_sum - i;
                        if (!want) ans++;
                    }
                }

            cout << ans << "\n";
        }
    }
}
