class Solution {
public:
    int modu = 1e9 + 7;
    int maxdept = 0;
    int pow(int a , int b){
        int res = 1;
        a = (a) % modu;
        while(b){
            if(b & 1 ){
                res = (1ll* res*a)%modu;
            }
            a = (1ll*(a % modu) * (a%modu))%modu;
            b /= 2;
        }
        return res;
    }
    void dfs(vector<vector<int>>& adj , int dept , int node, vector<bool>&vis){
        if(vis[node] ) return;
        vis[node] = true;
        maxdept = max(maxdept , dept);
        for(auto a : adj[node]){
            dfs(adj , dept + 1, a , vis);
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(auto a : edges){
            adj[a[0] - 1].push_back(a[1] - 1);
            adj[a[1] - 1].push_back(a[0] - 1);
        }
        vector<bool> vis(n+1 , false);
        dfs(adj , 0 , 0 , vis);
        return pow(2 , maxdept-1);
    }
};