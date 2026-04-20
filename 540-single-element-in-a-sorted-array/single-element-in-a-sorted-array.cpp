class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n;
        if(n == 1) return nums[0];
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mid == 0 and nums[mid] != nums[mid+1]) return nums[mid];
            if(mid == n-1 and nums[mid] != nums[mid-1]) return nums[mid];
            if(nums[mid-1] != nums[mid] and nums[mid] != nums[mid+1])
            return nums[mid];
            // 1 2 2 
            // agar odd index to
            if(mid%2){
                // agar uppar mila to niche hoga
            if(nums[mid] == nums[mid+1])
              r = mid-1;
            else l = mid+1;
            }
            else{
                // agar uppar mila
                if(nums[mid] == nums[mid+1])
                l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};