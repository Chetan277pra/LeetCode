class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> chota , bda;
        int same = 0;
        for(auto a : nums){
            if(a < pivot) chota.push_back(a);
            else if(a == pivot) same ++;
            else bda.push_back(a);
        }
        vector<int> ans =chota;
        while(same--) ans.push_back(pivot);
        for(auto a : bda) ans.push_back(a);
        return ans;
    }
};