class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int nn = nums.size();
        vector<int> p , n;
        for(int i = 0; i < nn; i++){
            if(nums[i] < 0) n.push_back(i);
            else p.push_back(i);
        }
        vector<int> ans;
        for(int i = 0; i < nn; i++){
            if(i%2) ans.push_back(nums[n[i/2]]);
            else ans.push_back(nums[p[i/2]]);
        }
        return ans;
    }
};