class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0, cand1 = 0, cand2 = 0;
        for(int i = 0; i < n; i++){
            if(count1 == 0 and nums[i] != cand2){
                count1++;
                cand1 = nums[i];
            }
            else if(count2 == 0 and nums[i] != cand1){
                count2++;
                cand2 = nums[i];
            }
            else if(nums[i] == cand1) count1++;
            else if(nums[i] == cand2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto a : nums) {
            if(a == cand1) count1++;
            else if(a == cand2) count2++;
        }
        int lim = n/3;
        if(count1 > lim and count2 > lim) return {cand1 , cand2};
        else if(count2 > lim) return {cand2};
        else if(count1 > lim) return {cand1};
        else return{};
    }
};