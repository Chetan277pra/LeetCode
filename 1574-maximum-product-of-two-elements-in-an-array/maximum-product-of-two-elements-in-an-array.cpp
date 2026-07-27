class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0 , sec = 0;
        for(auto a : nums){
            if(a > maxi){
                sec = maxi;
                maxi = a;
            }
            else if(a > sec) sec = a;
        }
        return maxi*sec - maxi - sec + 1;
    }
};