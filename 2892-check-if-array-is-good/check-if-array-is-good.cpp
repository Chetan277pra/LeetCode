class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size() - 1;
        int i = 0;
        for( i = 0; i < n; i++){
            if(nums[i] != i+1) return false;
        }
        return nums[i] == n;
    }
};