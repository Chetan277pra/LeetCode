class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n+1);
        for(int i = 0; i < n; i++)
        pref[i+1] = pref[i] + (i%2==0?nums[i]:-nums[i]);
        ll ans = pref[n];
        ll mn[2] = {-inf , -inf};
        
        for(int k = 2; k <= n; k++){
            int l = k-2;
            mn[l%2] = max(mn[l%2] , pref[l]);
            if(mn[k%2] != inf){
                ans = max(ans , pref[n] - 2ll*(pref[k] - mn[k%2] ));
            }
        }
        
        // mn[0] = mn[1] = -inf;
        // for(int k = 3; k <= n; k++){
        //     int j = k-1;
        //     mn[j%2] = max(mn[j%2] , pref[j]);
        //     int p = (k%2);
        //     if(mn[p%2] != inf){
        //         ans = max(ans , pref[n]-2ll * (
        //             pref[k] - mn[p]
        //         ));
        //     }
        // }
        return ans;
    }
};