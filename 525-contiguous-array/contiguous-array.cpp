class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        map<int , int> mpp;
        mpp[0] = -1;
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) curr--;
            else curr++;
            if(mpp.find(curr) != mpp.end()){
                maxi = max(maxi , i - mpp[curr] );
            }
            else mpp[curr] = i;
            // cout<<" i : "<<i<<"  curr : "<<curr<<endl;
            // for(auto a : mpp)cout<<a.first<<" "<<a.second<<endl;
        }
        return maxi;
    }
};