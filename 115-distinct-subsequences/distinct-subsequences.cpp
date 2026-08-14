class Solution {
public:
    int n, m;
    vector<vector<unsigned long long>> dp;

    unsigned long long rec(string &s, string &t, int i, int j) {
        // Entire t has been matched
        if (j == m)
            return 1;

        // s is exhausted
        if (i == n)
            return 0;

        if (dp[i][j] != ULLONG_MAX)
            return dp[i][j];

        unsigned long long ans = 0;

        // Don't take s[i]
        ans += rec(s, t, i + 1, j);

        // Take s[i] if it matches t[j]
        if (s[i] == t[j]) {
            ans += rec(s, t, i + 1, j + 1);
        }

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();

        dp.assign(n, vector<unsigned long long>(m, ULLONG_MAX));

        return rec(s, t, 0, 0);
    }
};