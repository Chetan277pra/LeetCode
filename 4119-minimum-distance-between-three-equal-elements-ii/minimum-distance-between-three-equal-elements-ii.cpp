class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        map<int , vector<int> > mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++) mpp[nums[i]].push_back(i);
        for(auto a : mpp){
            int m = a.second.size();
            int temp = 0;
            for(int i = 0; i < m-2; i++){
                temp += 2*a.second[i+2]- 2*a.second[i];
                ans = min(temp , ans);
                temp = 0;
            }
        }
        return ans==INT_MAX?-1 : ans;
    }
};