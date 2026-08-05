class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n );
        vector<bool> sus(n , false);
        for(auto a : inv ){
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
        }
        auto ntg = [&](auto && self , int k) -> void{
            if(sus[k]) return;
            sus[k] = true;
            for(auto a : adj[k]){
                self(self , a);
            }
        };
        ntg(ntg , k);
        for(auto a : inv){
            int u = a[0];
            int v = a[1];
            if (!sus[u] && sus[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!sus[i]) {
                ans.push_back(i);
            }
        }
        return ans;

    }
};