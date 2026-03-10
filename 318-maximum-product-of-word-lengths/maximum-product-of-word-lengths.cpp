class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size() , ans = 0;
        vector<int> vec(n , 0);
        for(int i = 0; i < n; i++){
            for(auto a : words[i]) vec[i] |= 1<<(a-'a');
            for(int j = 0; j < i; j++){
                if((vec[i] & vec[j]) == 0) 
                ans = max(ans ,((int)words[i].size())*((int)words[j].size()));
            }
        }
        return ans;
    }
};