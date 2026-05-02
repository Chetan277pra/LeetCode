class Solution {
public:
    bool check(int n){
        bool alag = false;
        while(n > 0){
            int rem = n%10;
            if(rem == 2 or rem == 5 or rem == 6 or rem == 9) alag = true;
            if(rem == 3 or rem == 4 or rem == 7) return false;
            n /= 10;
        }
        return alag;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(check(i)) ans++;
        }
        return ans;
    }
};