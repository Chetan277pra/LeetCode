class Solution {

    int rec(int pos , vector<int>& nums , vector<int> &dp){

        int n = nums.size();
        if(pos>=n-1) return 0;
        if(dp[pos]!=82) return dp[pos];
        // if (nums[pos] == 0)
        //     return INT_MAX;
        int mini=INT_MAX;
        for(int i=1 ; i<=nums[pos] ; i++){
            if(pos+i< n ){
            int result = rec(pos + i , nums , dp);
            if(result!=INT_MAX)
            mini = min(mini , 1+result);
            }
        }
        return dp[pos]=mini;
        
    }
public:
    int jump(vector<int>& nums) {
        int ans=0;
        vector<int> dp(nums.size()+1 , 82);
        return rec(ans , nums , dp);
    }
};