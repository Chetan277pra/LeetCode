class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int ans = 1;
        int i = 0;
        int maxi = nums[0];
        while(i <= maxi){
            int temp = i+1;
            if(maxi >= n-1) return ans;
            for(int j = i+1; j <= i+nums[i] and j < n; j++){
                if(j + nums[j] > maxi){
                    temp = j;
                    maxi = j + nums[j];
                }
            }
            ans++;
            i = temp;
            // cout<<i<<" "<<ans<<" " <<maxi<<endl;
            if(maxi >= n-1) return ans;
        }
        return -1;
    }
};