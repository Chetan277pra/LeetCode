class Solution {
public:
    long long mod = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void preff(int n) {
        fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
    }

    void invf(int n) {
        invFact.resize(n + 1);
        invFact[n] = power(fact[n], mod - 2);

        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % mod;
        }
    }

    long long ncr(int n, int r) {
        if (r > n || r < 0)
            return 0;
        return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
    }

    int countVisiblePeople(int n, int pos, int k) {
        preff(n); 
        invf(n);  

        int left = pos;
        int right = n - pos - 1;

        long long ans = 0;

        for (int i = max(0, k - right); i <= min(left, k); i++) {
            ans = (ans + ncr(left, i) * ncr(right, k - i) % mod) % mod;
        }

        return (ans * 2) % mod;
    }
};
