class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = -1;
        int n = nums.size();
        int temp = 0;
        int prev = 0;
        for(int i = 0; i < n; i++){
            temp += (nums[i] == 0)?1:0;
            if(temp > k){
                ans = max(ans , i - prev);
                while(prev < n and temp > k ){
                    if(nums[prev] == 0) temp--;
                    prev++;
                }
            }
        }
        ans = max(ans , n-prev);
        return ans;
    }
};