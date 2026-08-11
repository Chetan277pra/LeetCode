class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1){
                sum += nums[i];
            }
            else{
                break;
            }
        }
        sort(nums.begin() , nums.end());
        for(auto a : nums){
            if(a < sum) continue;
            if(a == sum) sum++;
            else return sum;
        }
        return sum;
    }
};