class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(auto a : prices){
            ans = max(ans , a - mini);
            mini = min(mini , a);
        }
        return ans;
    }
};