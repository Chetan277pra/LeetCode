class Solution {
public:
    int maxDistance(vector<int>& col) {
        int n = col.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(col[i] != col.back()) ans = max(ans , n - i - 1);
            if(col[n - i - 1] != col[0]) ans = max(ans , n-i-1);
        }
        return ans;
    }
};