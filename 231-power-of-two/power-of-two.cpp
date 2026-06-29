class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        // if(n < 0) n = -n;
        return (n&(n-1)) == 0;
    }
};