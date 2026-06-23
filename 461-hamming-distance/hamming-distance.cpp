class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if( ((x & (1<<i)) and !(y&(1<<i)) )
             or (!(x & (1<<i)) and (y&(1<<i)) )
            ) ans++;
        }
        return ans;
    }
};