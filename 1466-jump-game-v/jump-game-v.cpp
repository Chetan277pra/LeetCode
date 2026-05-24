class Solution {
public:
    int n;
    vector<int> dp;
    int answer(vector<int>& vec, int d, int ind){
        int ans = 1;
        if(dp[ind] != -1) return dp[ind];
        for(int i = 1; i <= d; i++){
            if(ind-i < 0) break;
            if(vec[ind-i] >= vec[ind]) break;
            ans = max(ans, 1 + answer(vec, d, ind-i));
        }

        for(int i = 1; i <= d; i++){
            if(ind+i >= n) break;
            if(vec[ind+i] >= vec[ind]) break;
            ans = max(ans, 1 + answer(vec, d, ind+i));
        }
        return dp[ind] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        int ans = 1;
        dp.resize(n , -1);
        for(int i = 0; i < n; i++){
            ans = max(ans, answer(arr, d, i));
        }
        return ans;
    }
};