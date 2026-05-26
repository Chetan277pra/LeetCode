class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int row = 0, col = mat[0].size()-1;
        while(row < n and col > -1){
            int curr = mat[row][col];
            if( curr == target) return true;
            else if(curr > target) col -= 1;
            else row += 1;
        }
        return false;
    }
};