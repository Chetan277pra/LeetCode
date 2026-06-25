class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        long long n = nums.size();
        long long  tc = 0;
        for(int i=0 ; i< n ; i++){
            long long ct = 0;
            for(int j = i ; j< n ; j++){
                if(nums[j] == target) ct++;
                int k = j-i +1;
                if(2*ct>k) tc++;
            }
        }
        return tc;
    }
};