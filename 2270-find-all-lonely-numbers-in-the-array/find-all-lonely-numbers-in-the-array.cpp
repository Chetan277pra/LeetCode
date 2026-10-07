class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        if(nums.size() == 1) return nums;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            if(i < n-1 and nums[i] == nums[i+1]) continue;
            if(i == 0 and i < n-1 and nums[i+1] != nums[i]+1) ans.push_back(nums[i]);
            else if(i > 0 and i == n-1 and nums[i-1] != nums[i] - 1 ) ans.push_back(nums[i]);
            else if(i > 0 and i < n-1) {
                if(nums[i-1] + 1 != nums[i]  and nums[i+1]-1 != nums[i]) ans.push_back(nums[i]);
            } 
        }
        return ans;
    }
};