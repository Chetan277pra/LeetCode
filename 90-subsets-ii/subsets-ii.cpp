class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void rec(vector<int>& vec , int ind,  vector<int> &tt){

        ans.push_back(tt);

        for(int i = ind ; i < n; i++){
            if(i > ind && vec[i] == vec[i-1]){
                continue;
            }
            tt.push_back(vec[i]);
            rec(vec , i+1 , tt);
            tt.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& vec) {
        vector<int> tt;
        sort(vec.begin(), vec.end());
        n = vec.size();
        rec(vec , 0 , tt);
        return ans;
    }
};