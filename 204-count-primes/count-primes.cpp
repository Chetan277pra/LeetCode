class Solution {
public:
    int seive(int n){
        if(n < 2) return 0;
        // cout <<" hi" 
        vector<int> ans;
        vector<bool> prime(n+1 , true);
        prime[0] = prime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(prime[i]){
                for(long long j = i * i; j <= n; j+=i){
                    prime[j] = false;
                }
            }
        }
        for(int i = 2; i <= n; i++){
            if(prime[i]) ans.push_back(i);
        }
        return ans.size();
    }
    int countPrimes(int n) {
        return seive(n-1);
    }
};