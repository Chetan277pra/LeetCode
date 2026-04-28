class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;
        for(auto a : grid){
            for(auto b : a ) vec.push_back(b);
        }
        sort(vec.begin() , vec.end());
        int si = vec.size();
        int aa = vec[0]%x;
        for(auto a : vec)
        if(a%x != aa) return -1;
        int mid = 0;
        if(si%2){ 
            mid = vec[si/2];
            int ans = 0;
            for(auto a : vec){
                ans = ans + (abs(a - mid) + x - 1) / x ;
            }
            return ans;
        }
        else{
            
            mid = (vec[si/2 -1] + vec[si/2])/2;
            int mid1 = vec[si/2 -1];
            int mid2 = vec[si/2];
            int ans1 = 0;
            int ans2 = 0;
            for(auto a : vec){
            ans1 = ans1 + (abs(a - mid1) + x - 1) / x ;
          }
           for(auto a : vec){
            ans2 = ans2 + (abs(a - mid2) + x - 1) / x ;
          }

          return min(ans1 , ans2);
          
        }
         
    }
};