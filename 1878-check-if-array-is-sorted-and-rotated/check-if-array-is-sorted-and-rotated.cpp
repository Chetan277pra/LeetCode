class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int pos = -1;
        int tot = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] < mini) {
                mini = nums[i];
                pos = i;
            }
        }
        for(int i = 1; i <= n; i++){
            if(nums[(pos+i-1)%n] > nums[(pos+i)%n]) {
                if(nums[(pos+i)%n] == mini) tot++;
                else
                return false;
            }
        }
        return (tot > 1)? false:true;
    }
};