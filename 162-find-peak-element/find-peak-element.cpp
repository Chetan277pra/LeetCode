class Solution {
public:
    int ans = -1;
    int n ;
    void rec(vector<int>& nums , int l , int r){
        if(l == r){
            if(l == 0 ) {
                if( nums[l] > nums[l+1])
                ans = l;
                return;
            } 
            else if(l == n-1 ){
                if( nums[l] > nums[l-1])
                ans = l;
                return;
            }
            else {
                if(nums[l-1] < nums[l] and nums[l] > nums[l+1])
                ans = l;
                return;
            }
        }
        int mid = l + (r-l)/2;
        rec(nums , l , mid);
        rec(nums , mid+1 , r);
        return;
    }
    int findPeakElement(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return 0;
        rec(nums , 0 , n-1);
        return ans;
    }
};