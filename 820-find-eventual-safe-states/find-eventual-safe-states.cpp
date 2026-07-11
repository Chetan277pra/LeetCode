class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n , 0);
        for(int i = 0; i < n; i++){
            for(auto a : graph[i]){
                adj[a].push_back(i);
                indeg[i]++;
            }
        }
        // for(auto a : indeg) cout <<a <<' ';
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++)
          if(indeg[i] == 0) q.push(i);
        while(!q.empty()){
            auto a = q.front(); q.pop();
            ans.push_back(a);
            for(auto it : adj[a]){
                if(--indeg[it] == 0) q.push(it);
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};