class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, maj = 0;
        for(auto a : nums){
            if(maj == 0) res = a;
            maj += res == a ? 1 : -1;
        }
        return res;
    }
};