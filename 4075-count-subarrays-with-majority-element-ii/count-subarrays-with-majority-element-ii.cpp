class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long n = nums.size();
        long long pre = n+1 , temp = n+1;
        vector<long long> pref( 2 *(n+1) , 0) , acc( 2*(n+1) , 0);
        pref[pre] = acc[pre] = 1;
        long long ans = 0;
        for(auto a : nums){
            temp += (a == target)? 1 : -1;
            pref[temp]++;
            acc[temp] = acc[temp-1] + pref[temp];
            ans += acc[temp-1];
        }
        return ans;
    }
};