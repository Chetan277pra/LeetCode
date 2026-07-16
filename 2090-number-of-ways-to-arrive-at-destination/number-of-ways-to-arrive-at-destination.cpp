class Solution {
public:
    int mod = 1e9 + 7;
    typedef long long  ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> adj(n);
        vector<int> ways(n , 0);
        ways[0] = 1;
        for(auto  a : roads){
            int u = a[0];
            int v = a[1];
            int w = a[2];
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        priority_queue<pair<ll , ll> , vector<pair<ll ,ll>>, greater<pair<ll , ll>> > q;
        vector<ll> dist(n , LLONG_MAX);
        dist[0] = 0;
        q.push({0 , 0});
        while(!q.empty()){
            auto  [d , node] = q.top(); q.pop();
            if(d > dist[node]) continue;
            for(auto a : adj[node]){
                if(dist[a.first] == d + a.second)
                  ways[a.first] = (ways[a.first] + ways[node])%mod;
                else if(dist[a.first] > d + a.second){
                    dist[a.first] = d + a.second;
                    ways[a.first] = ways[node];
                    q.push({dist[a.first] , a.first});
                }
                // cout<<node<<" "<<ways[node]<<" "<<
                // a.first<<" "<<ways[a.first]<<endl;
            }
        }
        return ways[n-1];
    }
};