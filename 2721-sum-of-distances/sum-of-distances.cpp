class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n);
        map<ll , vector<ll>> mpp;
        map<ll , vector<ll>> pref;
        for(ll i = 0; i < n; i++) mpp[nums[i]].push_back(i);
        for(auto a : mpp){
            int si = a.second.size();
            ll tot = 0;
            for(int i = 0; i < si; i++){
                tot += a.second[i];
                pref[a.first].push_back(tot);
            }
        }
        
        for(ll i = 0; i < n; i++){
            auto it = lower_bound(mpp[nums[i]].begin(), mpp[nums[i]].end(),i );
            int si = mpp[nums[i]].size();
            ll pahlekitne = it - mpp[nums[i]].begin();
            ll pahlesub = 0;
            if(pahlekitne > 0)
             pahlesub = pref[nums[i]][pahlekitne-1];
            else
             pahlesub = 0;
            
            // return {};
            ll pahleadd = pahlekitne*i;
            ll baadadd = pref[nums[i]][si-1] - pref[nums[i]][pahlekitne];
            ll baadsub = (mpp[nums[i]].size() - pahlekitne -1)*i;
            ll total = pahleadd + baadadd - pahlesub - baadsub;
            // cout<<pahleadd<<" "<<baadadd<<" "<<pahlesub<<" "<<baadsub<<endl;
            ans[i] = total;
        }
        return ans;
    }
};