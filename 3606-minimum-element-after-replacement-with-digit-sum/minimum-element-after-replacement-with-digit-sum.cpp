class Solution {
public:
    int check(int n){
        int count = 0;
        while(n > 0) {
            count += n%10;
            n /= 10;
        }
        return count;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto a : nums){
            mini = min(mini , check(a));
        }
        return mini;
    }
};