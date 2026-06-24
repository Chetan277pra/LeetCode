class Solution {
public:
    int n;
    vector<int> dp;
    bool ispal(string&s , int st , int end){
        while(st < end){
            if(s[st] != s[end]) return false;
            st++; end--;
        }
        return true;
    }
    int rec(string& s  , int ind){
        if(ind == n){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int ans = INT_MAX;
        for(int i = ind ; i < n; i++){
            int take = INT_MAX;
            if(ispal(s , ind , i)){
                take =  1 + rec(s , i+1) ;
            }
            ans = min(ans , take);
        }
        return dp[ind] =  ans;
    }
    int minCut(string s) {
        n = s.length();
        dp.assign(n+1 , -1);
        int ans = rec(s , 0);
        return ans-1;
    }
};