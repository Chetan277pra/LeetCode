class Solution {
public:
    map<int , string> mpp;
    vector<string> ans;
    int n;
    void rec(string & dig , int ind , string &s){
        if(ind == n){
            ans.push_back(s);
            return;
        } 
        int st = dig[ind] - '0';
        for(auto a : mpp[st]){
            s.push_back(a);
            rec(dig , ind+1 , s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mpp[1] = "";
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";
        n = digits.length();
        string temp = "";
        rec(digits  , 0 , temp);
        return ans;
    }
};