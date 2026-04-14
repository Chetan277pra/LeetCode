using ll = long long;
ll n, m;
vector<vector<ll>>dp;
class Solution {
public:
    ll rec(vector<int>&rob, vector<int> &pos, int ind1, int ind2){
        if(ind1 == n) return 0;
        if(ind2 == m) return 1e14;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        ll take = 0;
        take = abs(rob[ind1] - pos[ind2]) + rec(rob, pos, ind1+1, ind2+1);
        ll skip = rec(rob , pos , ind1, ind2+1);

        return dp[ind1][ind2] = min(take , skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> pos;
        sort(robot.begin() , robot.end());
        sort(factory.begin() , factory.end());
        n = robot.size();
        ll factsize = factory.size();
        for(int i = 0; i < factsize; i++){
            ll aa = factory[i][1];
            ll bb = factory[i][0];
            for(ll j = 0; j < aa; j++) pos.push_back(bb);
        }
        m = pos.size();
        dp.assign(n+1 , vector<ll>(m+1, -1));
        // for(auto a: pos)cout<<a<<" ";
        return rec(robot , pos, 0 , 0);
    }
};