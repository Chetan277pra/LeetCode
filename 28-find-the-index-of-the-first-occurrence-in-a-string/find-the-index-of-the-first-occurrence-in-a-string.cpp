class Solution {
public:
    int strStr(string hay, string need) {
        int hash = 0;
        int n = need.length();
        for(auto a : need){
            hash += (11 * (a - 'a')) + (n - (a - 'a'));
        }
        int curr = 0;
        int m = hay.length();
        for(int i = 0; i < m; i++){
            curr += (11 * (hay[i] - 'a')) + (n - (hay[i] - 'a'));
            if(i >= n) curr -= (11 * (hay[i-n] - 'a')) + (n - (hay[i-n] - 'a'));
            if(curr == hash){
                bool ok = true;
                for(int j = i; j >= 0 and j >= i-n+1; j--){
                    if(hay[j] != need[ n - 1 - (i-j)]) ok = false;
                }
                if(ok) return i-n+1;
            }
        }
        return -1;
    }
};