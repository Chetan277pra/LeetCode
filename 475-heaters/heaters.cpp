class Solution {
public:
    using ll = long long;
    int findRadius(vector<int>& houses, vector<int>& h) {
        int ans = INT_MIN;
        sort(h.begin() , h.end());
        for(auto a : houses){
            auto it = lower_bound(h.begin() , h.end() , a);
            if(it != h.begin()){
                auto p = prev(it);
                if(it != h.end())
                    ans = max(ans , min(*it-a , a - *p ));
                else ans = max(ans , a - *p); 
            }
            else ans = max(ans , *it - a);
        }
        return ans;
    }
};





