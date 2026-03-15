class Fancy {
public:
#define mod 1000000007
#define ll long long
    long long bp(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    vector<ll> vec;
    ll add = 0;
    ll mul = 1;
    Fancy() {
        
    }

    void append(int val) { 
        ll temp = ((val - add)%mod+mod) * bp(mul,mod-2)%mod;
        vec.push_back(temp);
    }

    void addAll(int inc) { 
        add = (add + inc)%mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= vec.size()) return -1;
        ll temp = vec[idx];
        temp = (((temp%mod) * mul%mod)%mod + add)%mod;
        return temp;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */