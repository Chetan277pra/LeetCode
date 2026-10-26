class Solution {
public:
    vector<pair<int , int>> dir = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}};
    int n , m;
    long long cal(vector<vector<int>>& grid, int k , int row , int col){
            if(row < 0 or col < 0 or row >= n or col >= m) return 0;
            if(grid[row][col] == 0) return 0;
            long long tot = grid[row][col]%k;
            grid[row][col] = 0;
            for(auto [a ,b] : dir){
                int nr = row + a;
                int nc = col + b;
                tot += cal(grid , k , nr , nc);
            }
            return tot;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    long long temp = cal(grid , k , i , j);
                    if(temp % k == 0) count++;
                }
            }
        }
        return count;
    }
};