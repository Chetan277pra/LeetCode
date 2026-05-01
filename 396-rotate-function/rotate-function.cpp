class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int tt = 0;
        for(int i = 0; i < n; i++) tt += i*nums[i];
        ans[0] = tt;
        int maxi = tt;
        int tot = accumulate(nums.begin() , nums.end() , 0);
        for(int i = 1; i < n; i++){
            ans[i] = tt + tot - n*(nums[n-i]);
            tt = ans[i];
            maxi = max(maxi , tt);
        }
        return maxi;
    }
};