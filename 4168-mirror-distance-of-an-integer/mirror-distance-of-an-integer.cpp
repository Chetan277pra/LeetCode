class Solution {
public:
    int rev(int n){
        int ans = 0;
        while(n > 0){
            int rem = n%10;
            ans *= 10;
            ans += rem;
            n /= 10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(rev(n) - n);
    }
};