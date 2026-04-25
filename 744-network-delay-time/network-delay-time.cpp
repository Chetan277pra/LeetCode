class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &a : times){
            int u = a[0];
            int v = a[1];
            int t = a[2];
            adj[u].push_back({v, t});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto it = pq.top(); 
            pq.pop();

            int d = it.first;
            int node = it.second;

            if(d > dist[node]) continue;

            for(auto &edge : adj[node]){
                int nextNode = edge.first;
                int weight = edge.second;

                if(d + weight < dist[nextNode]){
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};