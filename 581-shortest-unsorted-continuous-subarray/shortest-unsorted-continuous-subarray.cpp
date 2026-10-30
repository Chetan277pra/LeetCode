class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int right = 0, left = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi , nums[i]);
            if(maxi != nums[i]) right = i;
        }
        int mini = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            mini = min(mini , nums[i]);
            if(mini != nums[i]) left = i;
        }
        // cout << right << " " << left << endl;
        if(left == right) return 0;
        return right - left + 1;
    }
};