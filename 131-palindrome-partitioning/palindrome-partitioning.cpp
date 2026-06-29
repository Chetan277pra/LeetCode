class Solution {
public:
    int n;
    vector<vector<string>> ans;
    bool check(string s, int l , int r){
        while(l <= r){
            if(s[l] != s[r] ) return false;
            l++; r--;
        }
        return true;
    }
    void rec(string &s , int l, vector<string> temp){
        if(l == n){
            if(check(s , l , n)) ans.push_back(temp);
            else return;
            // temp.pop_back();
            // ans.push_back(temp);
            return;
        }
        for(int i = l; i < n; i++){
            if(check(s , l , i)){
                temp.push_back(s.substr(l , i-l+1));
                rec(s , i+1 , temp );
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> temp;
        rec(s , 0 , temp);
        return ans;
    }
};