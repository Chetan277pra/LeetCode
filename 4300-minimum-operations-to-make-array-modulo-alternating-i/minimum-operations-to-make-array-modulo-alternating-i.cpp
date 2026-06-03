class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> odd, even;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i%2){
                odd.push_back(nums[i]%k);
            }
            else even.push_back(nums[i]%k);
        }
        // for(auto a : even) cout<<a<<" ";
        // cout<<endl;
        // for(auto a : odd) cout<<a<<" ";
        // cout<<endl;
        int tota = 0, totb = 0;
        int ans = INT_MAX;
        for(int i = 0; i < k; i++){
            tota = 0;
            for(auto a : odd) tota += min(abs(i-a) , abs(k-abs(i-a)));
            for(int j = 0; j < k; j++){
                if(i == j) continue;
                totb = 0;
                // cout<<j<<" :: ";
                for(auto a : even){totb += min(abs(j-a) , abs(k - abs(j-a)));
                // cout<<totb<<" ";
                }
            // cout<<endl;
            // cout<<tota <<" " << totb <<" " <<i << " " <<j<<endl;
            ans = min(ans , tota + totb);
            }
        }
        return ans;

        
    }
};