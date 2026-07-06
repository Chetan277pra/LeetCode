class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin() , in.end() , [](vector<int> a , vector<int> b){
            if(a[0] == b[0] ) return a[1] > b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        int maxi = INT_MIN;
        for(auto a : in){
            if(a[1] > maxi){
                ans++;
                maxi = a[1];
            }
        }
        return ans;
    }
};