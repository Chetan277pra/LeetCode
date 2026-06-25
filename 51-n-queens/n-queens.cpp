class Solution {
public:
    vector<vector<string>> res;
    void rec(int n , int row , int &col , vector<string>& ans){
        if(row == n ){
            res.push_back(ans);
            // cout << "hi"<<endl;
            return;
        }
        for(int i = 0; i < n; i++){
            bool ok = true;
            int tt = ans.size();
            for(int j = 0; j < tt; j++){
                size_t pos = ans[j].find('Q');
                if (abs((int)pos - i) == tt - j) {ok = false; break;}
            }
            if(ok) {
                string temp(n , '.');
                temp[i] = 'Q';
                auto it = find(ans.begin() , ans.end() , temp);
                if(it != ans.end()) continue;
                // cout << temp << "\n";
                ans.push_back(temp);
                // for(auto a : ans) cout << a << "  " ;
                // cout << endl;
                rec(n , row + 1 , i , ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0; i < n; i++){
            vector<string> ans;
            string s(n , '.');
            s[i] = 'Q';
            // cout << s << " \n";
            ans.push_back(s);
            rec(n , 1 , i, ans);
        }
        return res; 
    }
};