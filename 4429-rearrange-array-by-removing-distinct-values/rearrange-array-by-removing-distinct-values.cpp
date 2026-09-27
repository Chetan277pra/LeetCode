class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int  , int> mpp;
        for(auto a : nums) mpp[a]++;
        vector<int> ans;
        bool ok= true;
        while(ok){
            ok = false;
            for(auto &a : mpp){
                if(a.second > 0){
                    ok = true;
                    ans.push_back(a.first);
                }
                a.second--;
            }
        }
        return ans;
    }
};