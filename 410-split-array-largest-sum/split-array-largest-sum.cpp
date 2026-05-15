class Solution {
public:
   int n;
    bool check(vector<int>&nums , int k , int curr){
        int tot = 1;
        int prev = 0;
        for(int i = 0; i < n; i++){
            prev += nums[i];
            if(nums[i] > curr) return false;
            if(prev > curr){
                tot++;
                prev = nums[i];
            }
            cout<<prev <<"  "<<tot<<endl;
        }
        return tot <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        int l = 0, r = INT_MAX;
        // bool a= check(nums , k , 1);
        // cout<<"i : "<<a;
        // return 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(check(nums , k , mid)){
                r = mid;
            }
            else l = mid+1;
        }
        return l;
    }
};