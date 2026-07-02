class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> pref(n , 0);
        pref[0] = card[0];
        for(int i = 1; i < n; i++){
            pref[i] += pref[i-1] + card[i];
        }
        int ans = 0;
        vector<int> suff(n , 0);
        suff[n-1] = card[n-1];
        for(int i = n-2; i >= 0; i--){
            suff[i] = suff[i+1] + card[i];
        }
        ans = pref[k-1];
        for(int i = 0; i < k-1; i++){
            ans = max(ans , pref[i] + suff[n-k+i+1] );
        }
        ans = max(ans , suff[n-k]);
        return ans;
    }
};