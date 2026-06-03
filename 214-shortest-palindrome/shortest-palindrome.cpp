class Solution {
public:
   vector<int> lpsarray(string & s){
        int n = s.length();
        vector<int> lps(n , 0);
        int i = 1 , k = 0;
        while(i < n){
            if(s[i] == s[k]) {
                lps[i++] = ++k;
            }
            else {
                if(k) k = lps[k-1];
                else i++;
            }
        }
        return lps;
   }

    string shortestPalindrome(string s) {
        string temp = s + '#';
        string t = s;
        reverse(t.begin() , t.end());
        temp += t;
        vector<int> lps = lpsarray(temp);
        // cout<<lps.back();
        string ss = s.substr(lps.back());
        reverse(ss.begin() , ss.end());
        return ss + s;
    }
};