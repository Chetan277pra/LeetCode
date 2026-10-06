class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 999999;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    int temp = nums[i] + nums[j] + nums[k];
                    // cout << temp<<" " << abs(target-temp)<<endl;
                    if(abs(target-temp) < abs(target-ans)) ans = temp; 
                }
            }
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};