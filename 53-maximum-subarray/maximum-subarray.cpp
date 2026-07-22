class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0;
        int maxi=INT_MIN;
        for(auto a:nums){
            pre=max(a,pre+a);
            maxi=max(maxi,pre);
        }
        return maxi;
    }
};