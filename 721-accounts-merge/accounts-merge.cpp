class DSU{
    public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.assign(n , 1);
        iota(parent.begin() , parent.end() , 0);
    }
    int find(int a){
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
    void uni(int a , int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(size[a] > size[b]) swap(a , b);
        parent[a] = b;
        size[b] += size[a];
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        map<string , int> mpp;
        int n = acc.size();
        DSU dsu(n);
        for(int i = 0; i < n; i++){
            for(auto a : acc[i]){
                if(a == acc[i].front()) continue;
                if(mpp.find(a) != mpp.end()){
                    dsu.uni(i , mpp[a]);
                    mpp[a] = i;
                }
                else{
                    mpp[a] = i;
                }
            }
        }
        vector<vector<string>> temp(n);
        int i = 0;
        for(auto a : acc){
            temp[i++].push_back(a.front());
        }
        for(auto a : mpp){
            int t = dsu.find(a.second);
            // cout << t << a.first << endl;
            temp[t].push_back(a.first);
        }

        vector<vector<string>> ans;
        for(auto a : temp){
            if(a.size() > 1) ans.push_back(a);
        }
        for(auto a : ans){
            sort(a.begin() +1 , a.end());
        }
        return ans;
    }
};































