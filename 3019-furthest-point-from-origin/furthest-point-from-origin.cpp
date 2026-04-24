class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int l = 0, r = 0;
        for(auto a : moves) 
        if(a == 'L') l++;
        else if(a == 'R') r++;
        int ans = max(l , r);
        ans += (n - (l+r) - min(l , r)) ;
        return ans;
    }
};