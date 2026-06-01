class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin() , cost.rend());
        int tot = 0;
        int n = cost.size();
        for(int i = 0; i < n; i++){
            if((i+1)%3 == 0) continue;
            tot += cost[i];
        }
        return tot;
    }
};