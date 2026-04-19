class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        sort(sources.begin() , sources.end(), [](vector<int> a, vector<int> b){
            return a[2] > b[2];
        });
        vector<vector<bool>> vis(n, vector<bool>(m , false));
        queue<vector<int>> q;
        vector<vector<int>> ans(n , vector<int>(m));
        vector<pair<int,int>> dir{{0 , -1} , {0,1} ,{1 ,0},{-1, 0}};
        for(auto a : sources){
            q.push({a[2] , a[0] , a[1]});
            vis[a[0]][a[1]] = true;
            ans[a[0]][a[1]] = a[2];
        }
        while(!q.empty()){
            int si = q.size();
            for(int i = 0; i < si; i++){
            vector<int> temp = q.front(); q.pop();
            int r = temp[1];
            int c = temp[2];

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({temp[0] , nr , nc});
                    vis[nr][nc] = true;
                    ans[nr][nc] = temp[0];
                }
            }
            }
            
        }
        return ans;
    }
};