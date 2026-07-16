class Solution {
public:
    int N;
    vector<vector<pair<int , int>>> adj;
    int dfs(int src , int thres){
        priority_queue< pair<int ,int> , vector<pair<int , int>> , greater<pair<int , int>> > pq;
        vector<int> dist(N , INT_MAX);
        dist[src] = 0;
        pq.push({0 , src});
        int tot = 0;
        while(!pq.empty()){
            auto [dis , no] = pq.top(); pq.pop();
            if(dis > thres) return tot;
            if(dis > dist[no])
            continue;
            tot++;
            for(auto a : adj[no]){
                if(dist[a.first] > dis + a.second){
                    dist[a.first] = dis + a.second;
                    pq.push({ dist[a.first] , a.first });
                }
            }
        }
        return tot;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        int ans = 0;
        N = n;
        int mini = INT_MAX;
        adj.resize(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        for(int i = 0; i < n; i++){
            int temp = dfs(i , th);
            if(temp <= mini){
                mini = temp;
                ans = i;
            }
        }
        return ans;
    }
};