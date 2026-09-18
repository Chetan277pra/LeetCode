class Solution {
public:
    int maximumUnits(vector<vector<int>>& vec, int truck) {
        sort(vec.begin() , vec.end() , [](vector<int> a , vector<int> b){
            return a[1] >= b[1];
        });
        int count = 0;
        int ans = 0;
        for(auto a : vec){
            int temp = min(truck-count , a[0]);
            count += temp;
            ans += temp*a[1];
            // cout << temp <<" " << count <<" " << ans <<endl;
        }
        return ans;
    }
};