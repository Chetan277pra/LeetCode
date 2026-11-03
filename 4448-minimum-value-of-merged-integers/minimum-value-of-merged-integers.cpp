class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i+=2){
            string s = to_string(nums[i]);
            s += to_string(nums[i+1]);
            ans = min(ans , stoi(s));
        }
        return ans;
    }
};