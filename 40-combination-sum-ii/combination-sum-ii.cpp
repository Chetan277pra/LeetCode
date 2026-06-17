class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void rec(vector<int>& vec , int &t , int ind, int temp, vector<int> &tt){
        if(temp > t) return;
        if(temp == t) {
            ans.push_back(tt);
            return;
        }
        if(ind >= n) return;

        // take same call same
        tt.push_back(vec[ind]);
        rec(vec , t , ind+1 , temp+vec[ind] , tt);
        tt.pop_back();

        // skip
        int nxt = ind+1;
        while(nxt < n and vec[nxt] == vec[ind] ) nxt++;
        rec(vec , t , nxt , temp , tt);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& vec, int target) {
        vector<int> tt;
        n = vec.size();
        sort(vec.begin() , vec.end());
        rec(vec , target , 0 , 0 , tt);
        vector<vector<int>> res;
        // for(auto &a : ans)
        //     sort(a.begin() , a.end());
        // set<vector<int>> temp;
        // for(auto a : ans){
        //     sort(a.begin() , a.end());
        //     temp.insert(a);
        // }
        // for(auto a : temp){
        //     res.push_back(a);
        // } 
        return ans;
    }
};