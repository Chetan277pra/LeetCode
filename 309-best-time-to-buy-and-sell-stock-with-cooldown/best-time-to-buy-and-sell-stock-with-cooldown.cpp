class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int rec(vector<int>& vec , bool buy , int ind){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans = 0;
        if(!buy){
            int take = -vec[ind] + rec(vec , 1 , ind+1);
            int skip = rec(vec , 0 , ind+1);
            ans = max(take , skip);
        }
        else{
            int take = vec[ind] + rec(vec , 0 , ind+2);
            int skip = rec(vec , 1 , ind+1);
            ans = max(take , skip);
        }
        return dp[ind][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n , vector<int>(2 , -1));
        int ans = rec(prices , 0 , 0);
        return ans;
    }
};