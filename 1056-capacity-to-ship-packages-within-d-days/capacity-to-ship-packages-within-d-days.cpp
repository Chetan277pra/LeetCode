class Solution {
public:
    bool check(vector<int>& weights, int d, int curr){
        int tot = 0;
        int days = 1;
        for(auto a : weights){
            if(a > curr) return false;
            tot += a;
            if(tot > curr){
                days++;
                tot = a;
            }
        }
        return days <= d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = INT_MAX;
        while(l < r){
            int mid = l + (r - l)/2;
            if(check(weights , days , mid)){
                r = mid;
            }
            else l = mid+1;
        }
        return l;
    }
};