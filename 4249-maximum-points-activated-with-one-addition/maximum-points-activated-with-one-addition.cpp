class Solution {

    class DSU{
        public:
        vector<int> parent , si;
        DSU(int n){
            parent.resize(n+1);
            si.resize(n+1 , 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int n){
            if(n == parent[n]) return n;
            return parent[n] = find(parent[n]);
        }
        void unite(int a , int b){
            a = find(a);
            b = find(b);
            if(si[b] > si[a] ) swap(a , b);
            parent[b] = a;
            si[a] += si[b];
        }
    };

public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        map<int,int> x , y;
        for(int i = 0;i < n; i++){
            if(x.count(points[i][0]))
            dsu.unite(i , x[points[i][0]]);
            else x[points[i][0]] = i;
            if(y.count(points[i][1]))
            dsu.unite(i , y[points[i][1]]);
            else y[points[i][1]] = i;
        }
        int pm = 0 , sm = 0;
        for(int i = 0; i < n; i++){
            if(dsu.parent[i] == i){
                if(dsu.si[i] > pm){
                    sm = pm;
                    pm = dsu.si[i];
                }
                else if(dsu.si[i] > sm) sm = dsu.si[i];
            }
        }
        return pm + sm + 1;
    }
};