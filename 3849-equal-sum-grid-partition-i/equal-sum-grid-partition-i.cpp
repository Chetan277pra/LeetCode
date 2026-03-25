class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long pref = 0;
        for(auto a : grid)
        for(auto b : a) pref += b;
        long long curr = 0, ver = pref;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                curr+=grid[j][i];
                ver -= grid[j][i];
            }
            if(curr == ver) return true;
        }
        curr = 0;
        ver = pref;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                curr += grid[i][j];
                ver -= grid[i][j];
            }
            if(curr == ver) return true;
        }
        return false;
    }
};