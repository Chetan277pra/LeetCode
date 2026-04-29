class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k , int curr){
        int tot = 0;
        int prev = 0;
        for(auto a : bloomDay){
            if(a <=  curr) prev++;
            else{
                tot += prev/k;
                prev = 0;
            }
        }
        return tot >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        bloomDay.push_back(INT_MAX);
        int l = 0, r = INT_MAX;
        while(l < r){
            int mid = l + (r - l)/2;
            if(check(bloomDay , m , k , mid)){
                r = mid;
            }
            else l = mid+1;
        }
        return l==INT_MAX?-1 : l;
    }
};