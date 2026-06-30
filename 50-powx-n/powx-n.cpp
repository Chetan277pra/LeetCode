class Solution {
public:
    double pow(double x , int n){
        double res = 1;
        while(n){
            if(n & 1) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1/x;
            if(n == INT_MIN) n = INT_MAX - 1;
            else
            n *= -1;
        }
        return pow(x , n);
    }
};