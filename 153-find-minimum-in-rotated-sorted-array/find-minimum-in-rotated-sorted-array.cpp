class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if(r==0) return nums[0];
        
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            // cout<<mid<<" "<<nums[mid]<<" "<<ans<<endl;
              ans = min(ans , nums[mid]);
            //   cout<<ans
            if (nums[l] <= nums[mid]) {
                ans = min(ans,nums[l]);
                l = mid+1;

            } else {
                ans = min(ans,nums[mid]);
                r=mid;
            }
            // cout<<ans<<" "<<mid<<" "<<" "<<l<<" "<<r<<endl;
        }
        return ans;
    }
};