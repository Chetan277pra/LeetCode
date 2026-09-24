class Solution {
public:
    int cal(int n){
        int tot = 0;
        while(n > 0) {
            tot += n%10;
            n /= 10;
        }
        return tot;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        if(i == cal(nums[i])) return i;
        return -1;
    }
};