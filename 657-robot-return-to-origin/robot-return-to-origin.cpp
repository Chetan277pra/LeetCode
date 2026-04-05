class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, r = 0;
        for(auto a : moves){
            if(a == 'U') u++;
            else if(a == 'D') u--;
            else if(a == 'L') r--;
            else r++;
        }
        return (u == 0 and r == 0);
    }
};