class Solution {
    map<int , int> mpp;
    int n;
    vector<int> dp;
    int rec(vector<int>& nums, int ind){

        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int skip = rec(nums , ind+1);
        int take = mpp[nums[ind]];
        int nind = ind;
        if(ind < n-1 and nums[ind+1] == nums[ind]+1) nind++;
        take += rec(nums , nind+1);
        // cout<<"ind: "<<ind<<" take : "<<take<<" skip : "<<skip<<endl;
        return dp[ind] = max(take , skip);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        for(auto a : nums) mpp[a] += a;
        set<int> s(nums.begin(), nums.end());
        vector<int> result(s.begin(), s.end());
        nums = result;
        n = nums.size();
        dp.assign(n+1 , -1);
        return rec(nums , 0);
    }
};