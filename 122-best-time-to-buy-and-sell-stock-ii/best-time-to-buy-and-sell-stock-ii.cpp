class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curr = prices[0];
        for(auto a : prices){
            ans += max(0 , a - curr);
            curr = a;
        }
        return ans;
    }
};