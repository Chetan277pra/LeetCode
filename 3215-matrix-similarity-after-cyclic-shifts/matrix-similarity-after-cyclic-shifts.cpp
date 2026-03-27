class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat;
        int n = temp.size();
        int m = temp[0].size();
        k %= m;
        for(int i = 0; i < n; i++){
            // odd
            if(i%2) {
                rotate(temp[i].begin(),temp[i].end()-k,temp[i].end());
            }
            else rotate(temp[i].begin(), temp[i].begin()+k,temp[i].end());
        }
        
        return temp == mat;
    }
};