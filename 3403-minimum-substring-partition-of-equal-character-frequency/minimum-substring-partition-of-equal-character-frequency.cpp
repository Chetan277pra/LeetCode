class Solution {
    
    int n;
    vector<int> dp;
    int rec(int ind , string &s){
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        vector<int> vec(26 , 0);

        int ans = INT_MAX;

        for(int i = ind; i < n; i++){
            int check = ++vec[s[i]-'a'];
            bool bal = true;
            for(auto a : vec) if(a != 0 and a != check) {bal = false ; break;}
            if(bal)
             ans = min(ans , 1 + rec(i+1 , s));
        }
        return dp[ind] = ans;
    }
public:
    int minimumSubstringsInPartition(string s) {
        n = s.size();
        dp.assign(n , -1);
        return rec( 0 , s);
    }
};