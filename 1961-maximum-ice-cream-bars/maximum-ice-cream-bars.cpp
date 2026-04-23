class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int tot = 0;
        int n = costs.size();
        for(int i = 0; i < n; i++){
            tot += costs[i];
            if(tot > coins) return i;
        }
        return n;
    }
};