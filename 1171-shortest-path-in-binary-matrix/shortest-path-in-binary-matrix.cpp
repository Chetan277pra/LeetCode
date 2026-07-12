class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int , int , int>> q;
        q.push({0 , 0 , 1});
        vector<pair<int , int>> dir = { {0 , -1} , {-1 , -1},{-1 , 0},
        {-1 , 1},{0 , 1},{1 , 1}, {1 , 0}, {1 , -1}   };
        while(!q.empty()){
            auto [x , y , d] = q.front(); q.pop();
            if(x == m-1 and y == n-1) return d;
            for(auto a : dir){
                int nx = x + a.first;
                int ny = y + a.second;
                if(nx >= 0 and ny >= 0 and nx < m and ny < n and grid[nx][ny]== 0) {
                    grid[nx][ny] = 1;
                    q.push({nx , ny , d+1});
                    }
            }
        }
        return -1;
    }
};