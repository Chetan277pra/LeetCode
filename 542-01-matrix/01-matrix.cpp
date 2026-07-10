class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(auto &a : mat){
            for(auto &b : a) if(b == 1) b = INT_MAX;
        }
        queue<pair<int , int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) q.push({i , j});
            }
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(auto a : dir){
                int i = x + a[0];
                int j = y + a[1];
                if(i >= 0 and j >= 0 and i < m and j < n and mat[i][j] != 0){
                    if(mat[i][j] > 1 + mat[x][y]){
                        mat[i][j] = 1 + mat[x][y];
                        q.push({i , j});
                    }
                }
            }
        }
        return mat;
    }
};