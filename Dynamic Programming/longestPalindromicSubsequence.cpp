class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int> > dp(n, vector<int> (n, 1));

        for(int i = 0; i < n-1; i++)
            if(s[i] == s[i+1]) dp[i][i+1] = 2;

        for(int sz = 2; sz < n; sz++){
            for(int i = 0; i + sz < n; i++){
                int j = i + sz;
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][n-1];
    }
};
