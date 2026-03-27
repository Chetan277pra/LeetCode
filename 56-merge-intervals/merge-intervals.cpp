class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin() , inter.end());
        vector<vector<int>> ans;
        ans.push_back(inter[0]);
        for(int i = 1; i < n; i++){
            vector<int> &last = ans.back();
            if(last[1] >= inter[i][0]){
                last[1] = max(last[1] , inter[i][1]);
            }
            else{
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};