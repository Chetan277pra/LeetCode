class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& que) {
        int n = nums.size();
        int mod = 1e9+7;
        for(auto a : que){
            int l = a[0];
            int r = a[1];
            int k = a[2];
            int m = a[3];
            for(int i = l; i <= r; i+=k) nums[i] = (1LL*nums[i]*m)%mod;
        }
        int ans = 0;
        for(auto a : nums) ans^=a;
        return ans;
    }
};