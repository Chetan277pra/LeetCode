class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        map<int , int> mpp;
        int curr = 0;
        mpp[0] = curr;
        for(int i = 1; i < n; i++){
            int diff = nums[i] - nums[i-1];
            if(diff <= maxDiff) mpp[i] = curr;
            else{
                mpp[i] = ++curr;
            }
            // cout <<i<<" " <<diff <<" "<<curr<<endl;
        }
        vector<bool> ans;
        for(auto a : q){
            ans.push_back(mpp[a[0]]==mpp[a[1]]);
        }
        return ans;
    }
};