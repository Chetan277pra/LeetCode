class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // int n = nums.size();
        int p = 0;
        int s = accumulate(nums.begin() , nums.end() , 0) ;
        vector<int> ans;
        for(auto a : nums){
            s -= a;
            ans.push_back(abs(s-p));
            p += a;
        }
        return ans;
    }
};