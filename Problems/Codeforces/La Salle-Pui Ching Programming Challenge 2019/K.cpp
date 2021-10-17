#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long dp[MAX][MAX] = { 0LL };
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 3; i < MAX; i += 2)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                dp[i][j] += dp[i - 2][k];

    long cnt[MAX];
    cnt[1] = 10LL;

    for (int i = 3; i < MAX; i += 2) {
        cnt[i] = cnt[i - 2];
        for (int j = 1; j < 10; j++)
            cnt[i] += dp[i][j];
    }

    int k;
    while (cin >> k) {
        int digits = 1;
        while (cnt[digits] < k)
            digits += 2;

        if (digits == 1)
            cout << (k - 1) << "\n";
        else {
            k -= cnt[digits - 2];

            long pots[MAX] = {1LL};
            for (int i = 1; i <= MAX / 2; i++)
                pots[i] = pots[i - 1] * 10LL;

            string ans(digits, '0');
            for (int i = 0, j = digits - 1; i <= j; i++, j--) {
                int digit = !i ? 1 : 0;
                int between = (j - 1) - (i + 1) + 1;
                int aux = (between + 1) / 2;

                while (digit < 10 && pots[aux] < k) {
                    digit++;
                    k -= pots[aux];
                }

                ans[i] = ans[j] = '0' + digit;
            }

            cout << ans << "\n";
        }
    }
}
