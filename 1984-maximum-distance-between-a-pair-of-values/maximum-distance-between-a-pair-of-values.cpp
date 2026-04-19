class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        int i = n-1, j = m-1;
        while(i > -1 and j > -1){
            if(nums2[j] < nums1[i]) j--;
            else{
                ans = max(ans , j - i);
                i--;
            } 
        }
        return ans;
    }
};