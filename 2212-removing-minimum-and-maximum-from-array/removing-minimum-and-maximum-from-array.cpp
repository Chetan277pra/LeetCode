class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxpos = 0, minpos = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxpos = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                minpos = i;
            }
        }
        int ans =  INT_MAX;
        int ll = minpos+1 , rl = n - minpos;
        int lh = maxpos+1 , rh = n-maxpos;
        ans = min(ans , max(ll , lh));
        ans = min(ans , max(rl , rh));
        ans = min(ans , ll + rh);
        ans = min(ans , lh + rl);
        return ans;
    }
};