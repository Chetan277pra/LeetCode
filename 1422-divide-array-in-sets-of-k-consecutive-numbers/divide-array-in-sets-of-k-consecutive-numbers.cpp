class Solution {
public:
    bool ok(vector<int>& nums , int ind , int k , int n){
        int i = ind + 1;
        int next = nums[ind] + 1;
        int count = 1;
        nums[ind] = -1;
        while(i < n and count  < k){
            if(next == nums[i]){
                next = nums[i] + 1;
                count++;
                nums[i] = -1;
            }
            i++;
        }
        return count == k;
    }
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k) return false;
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0)
            if(!ok(nums , i , k ,n)) return false;
        }
        return true;
    }
};