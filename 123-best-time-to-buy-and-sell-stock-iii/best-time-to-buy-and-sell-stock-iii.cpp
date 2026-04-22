class Solution {
    int n;
    vector<vector<vector<int>>> dp;
    int rec(vector<int>& arr, int ind, int tot, int hai) {
        if (ind == n or tot == 2)
            return 0;
        if (dp[ind][hai][tot] != 82)
            return dp[ind][hai][tot];
        // le rakha hai
        if (hai) {
            int bech = arr[ind] + rec(arr, ind + 1, tot + 1, 0);
            int skip = rec(arr, ind + 1, tot, 1);
            return dp[ind][hai][tot] = max(bech, skip);
        } else {
            int lele = -arr[ind] + rec(arr, ind + 1, tot, 1);
            int skip = rec(arr, ind + 1, tot, 0);
            return dp[ind][hai][tot] = max(lele, skip);
        }
    }

public:
    int maxProfit(vector<int>& arr) {
        n = arr.size();
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(2, 82)));
        return rec(arr, 0, 0, 0);
    }
};
