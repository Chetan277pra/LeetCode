class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n,1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }

    void uni(int a,int b) {
        a=find(a);
        b=find(b);

        if(a==b)
            return;

        if(sz[a]<sz[b])
            swap(a,b);

        parent[b]=a;
        sz[a]+=sz[b];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int OFFSET = 10001;

        DSU dsu(20002);

        unordered_set<int> nodes;

        for(auto &s:stones)
        {
            int row=s[0];
            int col=s[1]+OFFSET;

            dsu.uni(row,col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int tot=0;

        for(int node:nodes)
        {
            if(dsu.find(node)==node)
                tot++;
        }

        return stones.size()-tot;
    }
};