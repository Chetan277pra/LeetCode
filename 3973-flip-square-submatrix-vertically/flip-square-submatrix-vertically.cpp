class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int last = x+k-1;
        while(x < last){
        swap_ranges(grid[x].begin()+y , grid[x].begin()+y+k , grid[last].begin()+y );
        x++;
        last--;
        }
        return grid;
    }
};