class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();
        vector<bool> vis(n , false);
        vector<int> ans;
        if(m > n) return {};
        bool poora = true;
        while(poora){
            bool temp = false;
            for(int i = 0; i <= n-m; i++){
                if(vis[i]) continue;
                int j = 0;
                bool mila = true;
                bool real = false;
                for(; j < m; j++){
                    if( target[i+j] != '?' and target[i+j]!=stamp[j] ) {
                        mila = false;
                        break;
                    }
                    if(target[i+j] != '?') real = true;
                }
                if(mila and real){
                    temp = true;
                // cout<<"hi ";
                    vis[i] = true;
                    for(int k = i; k < i+m; k++) target[k] = '?';
                    ans.push_back(i);
                    // cout<<i<<endl;
                    // for(auto a : target) cout<<a<<" ";
                    // cout<<endl;
                }
            }
            if(!temp) break;
        }
        for(auto a : target) if(a != '?') return {};
         reverse(ans.begin() , ans.end());
         return ans;
    }
};