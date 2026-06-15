class Solution {
public:
    double rec(double x ,long long n , double res){
        if(n == 0) return res;
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        if(n%2){
            res = res * x;
        }
        return rec(x*x , n/2, res);
    }
    double myPow(double x, int n) {
       return rec(x , (long long)n , 1);
    }
};
