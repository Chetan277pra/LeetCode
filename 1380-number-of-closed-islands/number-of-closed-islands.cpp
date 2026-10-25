class Solution {
public:
    vector<pair<int , int>> dir = {{0 ,1}, {0,-1},{1,0},{-1,0}};
    int n , m;
    void dfs(vector<vector<int>>& grid, int row , int col){
        if(row < 0 or col < 0 or row >= n or col >= m) return;
        if(grid[row][col] == 1) return;
        grid[row][col] = 1;
        for(auto a : dir){
            int nr = row + a.first;
            int nc = col + a.second;
            dfs(grid , nr , nc);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        // upper // down
        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 0) dfs(grid , 0 , i);
            if(grid[n-1][i] == 0) dfs(grid , n-1 , i);
        }

        // left // right
        for(int i = 0;  i < n; i++){
            if(grid[i][0] == 0) dfs(grid , i , 0);
            if(grid[i][m-1] == 0) dfs(grid , i , m-1);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid , i , j);
                }
            }
        }
        return count;
    }
};