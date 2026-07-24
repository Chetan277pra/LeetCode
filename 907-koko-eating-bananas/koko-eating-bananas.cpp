class Solution {
public:
    bool check(vector<int>& piles , int h , int k){
        long long res = 0;
        for(long long a : piles) res += (a + k - 1)/k;
        return res <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MAX;
        int res = 0;
        while(l < r){
            int mid = l + (r - l)/2;
            if(check(piles , h , mid)){
                res = mid;
                r = mid;
            }
            else l = mid+1;
        }
        return res;
    }
};