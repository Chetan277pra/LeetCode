class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<int> pos(k+1 , 0);
        pos[0] = 1;
        int pre = 0;
        for(int i = 0; i < n; i++){
            pre += nums[i];
            while(pre < 0) pre += k;
            pre %= k;
            ans += pos[pre];
            pos[pre]++;
        }
        return ans;
    }
};