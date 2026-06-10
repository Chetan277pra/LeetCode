class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            int l = i;
            int r = i;
            while(l >= 0 and r < n and s[l] == s[r]) l--, r++;
            string temp = s.substr(l + 1 , r - l - 1);
            if(temp.length() > ans.length()) ans = temp;
            l = i-1;
            r = i;
            while(l >= 0 and r < n and s[l] == s[r]) l--, r++;
            temp = s.substr(l + 1 , r-l - 1);
            if(temp.length() > ans.length()) ans = temp;
        }
        return ans;
    }
};