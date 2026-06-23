class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int totalsum=(n*(n+1))/2;
        int arrsum= accumulate(nums.begin() , nums.end() , 0);
        return totalsum-arrsum;
    }
};