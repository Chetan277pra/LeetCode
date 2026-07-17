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
    int makeConnected(int n, vector<vector<int>>& con) {
        int m = con.size();
        if( m < n-1) return -1;
        DSU dsu(n);
        for(auto a : con){
            int u = a[0] , v = a[1];
            dsu.uni(u , v);
        }
        int tot = 0;
        for(int i = 0; i < n; i++)
        if(i == dsu.parent[i]) tot++;
        return tot-1;
    }
};