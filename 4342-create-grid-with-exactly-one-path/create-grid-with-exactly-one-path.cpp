class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        if(m == 0) return ans;
        string temp(n , '.');
        ans.push_back(temp);
        for(int i = 1; i < m; i++){
            string tt(n , '#');
            tt.back() = '.';
            ans.push_back(tt);
        }
        return ans;
    }
};