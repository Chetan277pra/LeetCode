class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        map<int , int > mpp;
        int pref = 0;
        mpp[0] = 1;
        for(auto a : nums){
            pref += (a%2);
            if(mpp.find(pref - k) != mpp.end())
              ans += mpp[pref - k];
            mpp[pref] += 1;
        }
        return ans;
    }
};