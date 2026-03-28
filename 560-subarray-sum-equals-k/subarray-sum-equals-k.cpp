class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n , 0);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] + nums[i];
        }
       if(*min_element(nums.begin() , nums.end())>k) return 0;
        int ans = 0;
        map<int ,int> vis;
        vis[0]++;
        for(auto a : pref){
            ans += vis[a-k];
            vis[a]++;
        }

        return ans;
    }
};