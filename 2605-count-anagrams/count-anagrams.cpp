class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    ll powexpo(ll a , ll b){
        ll res = 1;
        while( b >= 1){
            if(b & 1) res = ((res%mod) *  (a%mod))%mod;
            a = ((a%mod) * (a%mod))%mod;
            b >>= 1;
        }
        return res;
    }

    
    vector<ll> fact;

    int countAnagrams(string s) {
        fact.resize(1e5+1);
        s += ' ';
        ll curr = 1;
        fact[0] = 1;
        ll ans = 1;
        for(int i = 1; i < 1e5+1; i++){
            curr = (curr*i)%mod;
            fact[i] = curr;
        }

        int tot = 0;
        vector<int> vec(26 , 0);
        int n = s.length();
        int k = 0;
        // cout<<"pow: "<<powexpo(2 , 10)<<endl;
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                int len = i-k;
                k = i+1;
                ll here = 1;
                ll tt = 1;
                for(int j = 0; j < 26; j++) if(vec[j]>0)  tt = ((tt%mod) *fact[ vec[j]]%mod)%mod;
                here = ((fact[len] %mod) * (powexpo(tt,mod-2)%mod))%mod;
                ans = ((ans%mod) * (here%mod))%mod;
                // cout<<"len: "<<len<<" f: "<<fact[len]<<" tt: "<<tt<<" here: "<<here<<endl;
                vec.assign(26 , 0);
            }
            else
            vec[s[i]-'a']++;
        }
                
        
        return ans;
    }
};