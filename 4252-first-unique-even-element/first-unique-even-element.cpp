class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> mpp;
        for(auto a : nums) mpp[a]++;
        for(auto a : nums){
            if(!(a%2) and mpp[a] == 1) return a;
        }
        return -1;
    }
};