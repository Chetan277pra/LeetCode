class Solution {
public:
    int l = 0;
    int r = INT_MAX;
    int ans = 0;
    int mySqrt(int x) {
        while(l < r){
            long long mid = l + (r-l)/2;
            if(mid*mid <= x) {
                ans = mid;
                l = mid+1;
            }
            else r = mid;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
        }
        return ans;
    }
};