class Solution {
public:
    vector<vector<int>> dp;
    int rec(string &s , int ind1 , int ind2){
        if(ind1 == ind2) return 0;
        if(ind1 > ind2) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s[ind1] == s[ind2]) {
            return dp[ind1][ind2] = rec(s , ind1+1 , ind2-1);
        }
        int skip = 0;
        skip = 1 + min( rec(s , ind1+1 , ind2), rec(s , ind1, ind2-1));
        return dp[ind1][ind2] = skip;
    }
    int minInsertions(string s) {
        int n = s.length();
        dp.assign(n , vector<int>(n , -1));
        return rec(s , 0 , n-1);
    }
};