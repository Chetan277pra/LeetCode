class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int l = 0, r = nums.size()-1;

        while (l < r+1 && nums[l] == nums[r])
            l++;
        // cout<<l<<" "<<r;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[l] <= nums[mid]){
                ans = min(ans , nums[l]);
                l = mid+1;
            }
            else{
                ans = min(ans , nums[mid]);
                r = mid;
            }
        }
        return ans;
    }
};