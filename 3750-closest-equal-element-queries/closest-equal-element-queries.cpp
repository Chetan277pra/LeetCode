class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int , vector<int>> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            mpp[nums[i]].push_back(i);
        vector<int> ans;
        
        for(auto a : queries){
            int ele = nums[a];
            if(mpp[ele].size() == 1) {
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(mpp[ele].begin(), mpp[ele].end(), a);
            // agau aage nhi hai
            if(it == mpp[ele].begin()){
            int prev = mpp[ele].back();
            prev = min(abs(a - prev) , n - abs(a - prev));
            auto ne = next(it);
            int aa = abs(a - *ne);
            ans.push_back(min(aa , prev));
            }
            
            else{
                auto ne = next(it);
                int next = 0;
                int pr = 0;
                auto pre = prev(it);
                if(ne == mpp[ele].end()) next = mpp[ele][0];
                else next = *ne;
                pr = abs(a - *pre);
                next = min(abs(next - a) , n - abs(next - a));
                // cout<<next<<" "<<pr<<endl;
                int aa = min(next, pr);
                ans.push_back(aa);
            }
        }
        return ans;
    }
};