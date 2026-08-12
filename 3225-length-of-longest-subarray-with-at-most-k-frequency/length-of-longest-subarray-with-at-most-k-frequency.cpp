class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int , int> mpp;
        int ans = 0;
        int prev = 0;
        int n = nums.size();
        for(int i =0; i < n ; i++){
            int a = nums[i];
            mpp[a]++;
            if(mpp[a] > k){
                while(prev < i and mpp[a] > k){
                //    cout << mpp[a]<<endl;
                    mpp[nums[prev]]--;
                    prev++;
                }
            }
            ans = max(ans , i - prev +1);
            // cout << ans <<" a : "<< a<<endl;
        }
        return ans;
    }
};