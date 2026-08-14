class Solution {
    vector<vector<int>> dp;
    int rec(string& word1, string& word2, int i, int j) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (i == n1)
            return n2 - j;
        if (j == n2)
            return n1 - i;
        if(dp[i][j]!=-1) return dp[i][j];
        if (word1[i] == word2[j])
            return rec(word1, word2, i + 1, j + 1);
        int ins = 1 + rec(word1, word2, i, j + 1);
        int del = 1 + rec(word1, word2, i + 1, j);
        int rep = 1 + rec(word1, word2, i + 1, j + 1);

        return dp[i][j] = min({ins, del, rep});
    }

public:
    int minDistance(string word1, string word2) {
        dp = vector<vector<int>>(501 , vector<int> (501 , -1));
        return rec(word1, word2, 0, 0);
    }
};

