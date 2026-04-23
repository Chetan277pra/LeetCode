class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int ans = max(mini , maxi);
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int a = min(nums[i] , min(mini*nums[i] , maxi*nums[i]));
            int b = max(nums[i] , max(mini*nums[i] , maxi*nums[i]));
            mini = a; maxi = b;
            ans = max(ans , maxi);
            cout<<mini<<" "<<maxi<<" "<<ans<<endl;
        }
        return ans;

    }
};