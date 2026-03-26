class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n , vector<int>(n , INT_MAX));
        for(int i = 0; i < n; i++) dp[n-1][i] = mat[n-1][i];
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int left = (j > 0) ? dp[i+1][j-1] : INT_MAX/1000;
                int down = dp[i+1][j];
                int right = (j < n-1)? dp[i+1][j+1] : INT_MAX/1000;
                dp[i][j] = mat[i][j] + min(down , min(left , right));
            }
            // for(auto a : dp){
            // for(auto b : a) { cout <<b<<" ";} cout << endl;}
            // cout<<endl;
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) ans = min(ans , dp[0][i]);
        return ans;
    }
};