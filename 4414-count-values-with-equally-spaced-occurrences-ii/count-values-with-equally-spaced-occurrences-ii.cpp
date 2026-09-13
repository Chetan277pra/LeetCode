class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int , vector<int>> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto a : mpp){
            if(a.second.size() < 3) continue;
            int m = a.second.size();
            bool ok = true;
            for(int i = 1; i < m-1; i++){
                if(a.second[i] - a.second[i-1] != a.second[i+1] - a.second[i]) {
                    ok = false; break;
                }
            }
            if(ok)
            count++;
        }
        return count;
    }
};