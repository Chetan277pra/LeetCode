class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0;
        ll tot = 0;
        int n = nums.size();
        int count = 0;
        ll maxi = *max_element(nums.begin() , nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi) count++;
            while(count >= k){
                if(nums[left] == maxi) count--;
                left++;
            }
            tot += left;
        }
        return tot;
    }
};