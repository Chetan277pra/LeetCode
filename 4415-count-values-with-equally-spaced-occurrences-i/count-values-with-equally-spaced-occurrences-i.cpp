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
            if(a.second.size() != 3) continue;
            if(a.second[1] - a.second[0] == a.second[2]-a.second[1])
            count++;
        }
        return count;
    }
};