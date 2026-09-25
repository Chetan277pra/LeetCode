class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        vector<int> perm;
        vector<bool> used(n , false);
        int mask = (1<<15) -1;
        int rem = n;
        while(rem){
            bool found = false;
            for(int i = 0; i < n; i++){
                if(!used[i] && (nums[i]&mask) == mask){
                    used[i] = true;
                    perm.push_back(nums[i]);
                    rem--;
                    found = true;
                }
            }
            if(found) continue;
            int best = -1;
            int val = -1;
            for(int i = 0; i < n; i++){
                if(!used[i] && (nums[i]&mask) > val){
                    val = nums[i] & mask;
                    best = i;
                }
            }
            used[best] = true;
            perm.push_back(nums[best]);
            rem--;
            mask &= nums[best];
        }
        // for(auto a : perm) cout << a << " ";
        vector<int> ans(15 , 0);
        mask = (1 << 15) -1;
        for(int i = 0; i < n; i++){
            mask &= perm[i];
            for(int b = 14; b >= 0; b--){
                if(mask & (1<<b)) 
                ans[14-b] = i+1;
            }
        }
        return ans;
    }
};