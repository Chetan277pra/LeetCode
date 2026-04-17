class Solution {
public:
    int rev(int nums){
        if(nums == 0) return 0;
        int ans = 0;
        while(nums > 0){
            int rem = nums%10;
            ans *= 10;
            ans += rem;
            nums /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans  = INT_MAX;
        map<int , int> mpp;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            int a = nums[i];
            int lga = a;
            while(a > 0){
                int rem = a%10;
                if(rem != 0) break;
                a /= 10; 
            }
            int temp = rev(a);
            if(mpp.find(temp) != mpp.end()){
                ans = min(ans , mpp[temp] - i);
            }
            mpp[lga] = i;
            // cout<<a<<" "<<temp<<" "<<ans<<" : ";

        }
        return (ans==INT_MAX)?-1 : ans;
    }
};