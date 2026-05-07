class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> suff(n);
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
        pref[i] = max(nums[i] , pref[i-1]);
        }
        suff[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
        suff[i] = min(suff[i+1] , nums[i]);
        }

        // for(auto a : pref) cout<<a << " ";
        // cout<<endl;
        // for(auto a : suff) cout<<a<<" ";
        // cout<<endl;
        vector<int> ans(n);
        ans[n-1] = pref[n-1];
        for(int i = n-2; i >= 0; i--){
            if(pref[i] > suff[i+1]) ans[i] = ans[i+1];
            else ans[i] = pref[i];
        }
        return ans;
    }
};