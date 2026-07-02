class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int n = nums.size();
        map<int , int> mpp;
        mpp[0] = 1;
        int pref = 0;
        for(auto a : nums){
            pref += a;
            if(mpp.find(pref - goal) != mpp.end()){
                ans += mpp[pref-goal];
            }
            mpp[pref] += 1;
        }
        return ans;
    }
};