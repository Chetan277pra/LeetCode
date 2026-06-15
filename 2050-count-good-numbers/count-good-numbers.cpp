class Solution {
public:
    int mod  = 1e9 + 7;
    long long power(long long a , long long b){
        long long res = 1;
        while(b){
            if(b&1) res = (res * a)%mod;
            a = (a * a )%mod;
            b = b/2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long even = (n + 1 )/2;
        long odd = n - even;
        long long ans = (power(5 , even) * power(4 , odd))%mod;
        return ans;
    }
};