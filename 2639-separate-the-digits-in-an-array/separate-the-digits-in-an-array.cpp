class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = n-1 ; i >= 0; i--){
            int a = nums[i];
            while(a > 0){
                ans.push_back(a%10);
                a /= 10;
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};