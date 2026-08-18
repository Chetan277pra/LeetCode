class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // if(k == 1) return *max_element(nums.begin() , nums.end());
        map<int , int> mpp;
        for(auto a : nums) mpp[a]++;
        if(k == 1){
            int ans = -1;
            for(auto a : mpp){
                if(a.second == 1) ans = max(ans , a.first);
            }
            return ans;
        }
        if(k == nums.size()){
            return *max_element(nums.begin() , nums.end());
        }
        if(mpp[nums.front()] == mpp[nums.back()] and mpp[nums.front()] == 1)
            return max(nums.front() , nums.back());
        else if(mpp[nums.front()] == 1) return nums.front();
        else if(mpp[nums.back()] == 1) return nums.back();
        else return -1;
    }
};