class Solution {
public:
    vector<vector<vector<bool>>> vis;
    int row, col, ans = INT_MAX;
    void rec(vector<vector<int>>& grid, int i, int j, int curr) {

        if (i == row - 1 && j == col - 1) {
            ans = min(ans, curr);
            return;
        }

        // right
        if (j < col - 1) {
            int nx = curr ^ grid[i][j + 1];
            if (!vis[i][j + 1][nx]) {
                vis[i][j + 1][nx] = true;
                rec(grid, i, j + 1, nx);
            }
        }
        if (i < row - 1) {
            int nx = curr ^ grid[i + 1][j];
            if (!vis[i + 1][j][nx]) {
                vis[i + 1][j][nx] = true;
                rec(grid, i + 1, j, nx);
            }
        }
    }
    int minCost(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vis.resize(row, vector<vector<bool>>(col, vector<bool>(1024, false)));
        rec(grid, 0 , 0 , grid[0][0]);
        return ans;
    }
};