class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int sum = 0;
        while(n){
            if(n%10 == 0){
                n /= 10;
                continue;
            }
            ans = ans*10 + n%10;
            sum += n%10;
            n /= 10;
        }
        long long temp = 0;
        while(ans){
            temp = temp *10 + ans%10;
            ans /= 10;
        }
        // cout << ans << " " << sum;
        return temp*sum;
    }
};