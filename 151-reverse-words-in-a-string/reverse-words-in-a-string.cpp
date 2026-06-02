class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        s += " ";
        string temp = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(temp.length() > 0) res.push_back(temp);
                temp = "";
            }
            else temp.push_back(s[i]);
        }
        reverse(res.begin() , res.end());
        string ans = "";
        int m = res.size();
        for(int i = 0; i < m; i++){
            ans += res[i];
            if(i != m-1) ans += " ";
        }
        return ans;
    }
};