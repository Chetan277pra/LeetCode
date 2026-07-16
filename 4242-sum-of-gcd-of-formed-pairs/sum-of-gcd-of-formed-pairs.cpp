class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = 0;
        for(auto & a : nums){
            maxi = max(a , maxi);
            a = __gcd(a , maxi);
        }
        sort(nums.begin() , nums.end());
        int l = 0 , r = nums.size()-1;
        long long sum = 0;
        while(l < r){
            sum += __gcd(nums[l++] , nums[r--]);
        }
        return sum;
    }
};