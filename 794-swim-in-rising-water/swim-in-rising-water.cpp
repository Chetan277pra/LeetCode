class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        pq.push({grid[0][0], {0,0}});
        dist[0][0] = grid[0][0];

        vector<pair<int,int>> dir = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int cost = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;

            if(x==n-1 && y==n-1)
                return cost;

            for(auto d:dir){

                int nx=x+d.first;
                int ny=y+d.second;

                if(nx<0 || ny<0 || nx>=n || ny>=n)
                    continue;

                int newCost=max(cost,grid[nx][ny]);

                if(newCost<dist[nx][ny]){

                    dist[nx][ny]=newCost;

                    pq.push({newCost,{nx,ny}});
                }
            }
        }

        return -1;
    }
};