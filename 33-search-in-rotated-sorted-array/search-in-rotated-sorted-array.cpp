class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            // first sorted 
            if(nums[mid] == target) return mid;
            if(mid < n-1 and nums[mid+1] == target) return mid+1; 
            if(nums[l] < nums[mid]){
                if(nums[l] <= target and nums[mid] >= target) r = mid-1;
                else l = mid+1;
            }
            else{
                if(target <= nums[r] and target >= nums[mid])
                l = mid+1;
                else r = mid-1;
                 
            }
        }
        return -1;
    }
};