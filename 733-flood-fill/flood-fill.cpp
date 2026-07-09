class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int , int>> dir = {{0 , 1}, {0 , -1}, {1 , 0}, {-1 , 0}};
        queue<pair<int , int>> q;
        q.push({sr , sc});
        int m = image.size();
        int n = image[0].size();
        int same = image[sr][sc];
        vector<vector<bool>> vis(m , vector<bool>(n , false));
        while(!q.empty()){
            auto [x , y] = q.front(); q.pop();
            image[x][y] = color;
            vis[x][y] = true;
            // cout <<x <<" " << y<<" : ";
            for(auto d : dir){
                int i = x + d.first;
                int j = y + d.second;
                if(i >= 0 and j >= 0 and i < m and j < n and image[i][j] == same and !vis[i][j]){
                // cout <<i<<" " <<j <<"\n";
                    q.push({i , j});
                }
            }
        }
        return image;
    }
};