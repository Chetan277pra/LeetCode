class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = 0;
        int n = s.length();
        string ans = "";
        int bal = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(') bal++;
            else bal--;
            if(bal == 0){
                string temp = s.substr(l+1 , i-l-1);
                l = i+1;
                ans += temp;
            }
        }
        return ans;
    }
};