class Solution {
public:
    set<vector<int>> res;
    int n;
    void twosum(vector<int>& nums, int ind1,int ind2,  long long target){
        int j = n-1;
        int i = ind2+1;
        while(i < j){
            // while(i < j and nums[j] == nums[j-1]) j--;
            // while(i < j and nums[i] == nums[i+1]) i++;
            // cout<<" i : "<<i<<"  j : "<<j<<endl;
            // cout<<nums[i]<<nums[j]<<endl;
            // cout<<target<<endl;
            if(nums[i]+nums[j] < target)  i++;
            else if(nums[i] + nums[j] > target) j--;
            else {res.insert({nums[i],nums[j],nums[ind1],nums[ind2]});
            i++; j--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        // for(auto a : nums) cout<<a<<" ";
        // cout<<endl;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                // cout<<"   next     jhjhjhjhjhjhjh    "<<endl;
                long long temp = (long long)target - nums[i] - nums[j];
                // cout<<target<<" "<<nums[i]<<" "<<nums[j]<< endl;
                // cout<<temp<<endl;
                twosum(nums , i, j , temp);
            }
        }
        vector<vector<int>> ans(res.begin() , res.end());
        for(auto &a : ans) sort(a.begin() , a.end());
        return ans;
    }
};