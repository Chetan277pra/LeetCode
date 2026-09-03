class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odd = 0 , even = 0 , mini = INT_MAX;
        for(auto a : nums){
            odd += (a%2 == 1);
            even += (a%2 == 0);
            mini = min(mini , a);
        }
        if(mini%2 == 0 and odd > 0) return false;
        // if(mini%2 == 1 and even > 0) return false;
        return true;
    }
};