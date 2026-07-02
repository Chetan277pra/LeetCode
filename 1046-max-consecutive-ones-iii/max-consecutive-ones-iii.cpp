class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int l = 0;
        int curr0 = 0;
        for(int i = 0; i < n; i++){
            curr0 += (nums[i] == 0);
            while(curr0 > k){
                curr0 -= (nums[l] == 0);
                l++;
            }
            ans = max(ans , i-l+1);
        }
        return ans;
    }
};