class Solution {
public:
    set<vector<int>> ans;
    int n;
    void rec(vector<int>& vec , int &t , int ind, int temp, vector<int> &tt){
        if(ind >= n) return;
        if(temp > t) return;
        if(temp == t) {
            ans.insert(tt);
            return;
        }
        // skip
        rec(vec , t , ind+1 , temp , tt);
        // take same call same
        tt.push_back(vec[ind]);
        rec(vec , t , ind , temp+vec[ind] , tt);
        rec(vec , t , ind +1 , temp + vec[ind] , tt);
        tt.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& vec, int target) {
        vector<int> tt;
        n = vec.size();
        rec(vec , target , 0 , 0 , tt);
        vector<vector<int>> res;
        for(auto a : ans) res.push_back(a);
        return res;
    }
};