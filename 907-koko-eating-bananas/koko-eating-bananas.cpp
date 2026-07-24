class Solution {
public:
    bool check(vector<int> piles, int mid , int h){
        int tot = 0;
        for(auto a : piles){
            tot += (a + mid-1)/mid;

        }
        return tot <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1 , r = INT_MAX;
        while(l < r){
            int mid = l + (r - l)/2;
            if(check(piles , mid , h)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};