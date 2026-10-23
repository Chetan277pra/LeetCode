class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = pow(2 , 31) - 1;
        // cout << ans << endl;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // cout << ans << " ";
            if(nums[i] != i) ans &= nums[i];
            // cout << ans <<"\n";
        }
        if(ans == pow(2 , 31) - 1) ans = 0;
        return ans;
    }
};