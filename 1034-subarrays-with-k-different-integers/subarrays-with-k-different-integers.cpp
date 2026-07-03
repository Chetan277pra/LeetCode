class Solution {
public:
    int cal(vector<int> & nums, int k){
        int n = nums.size();
        int l = 0;
        int ans = 0;
        map<int , int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
            while(mpp.size() > k) {
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // cout << cal(nums , k);
        // cout << endl << cal(nums , k-1);
        return cal(nums , k) - cal(nums , k-1);
    }
};