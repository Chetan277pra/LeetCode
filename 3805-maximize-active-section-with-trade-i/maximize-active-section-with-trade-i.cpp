class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int curz = 0, lasz = 0, conv = 0, one = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') curz++;
            else{
                if(curz != 0) lasz = curz;
                curz = 0; one++;
            }
            conv = max(conv , curz + lasz);
        }
        if(conv == curz or conv == lasz) return one;
        else return one + conv;
    }
};