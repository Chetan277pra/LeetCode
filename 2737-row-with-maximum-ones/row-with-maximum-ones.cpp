class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ans = 0;
        int maxi = 0;
        int n = mat[0].size();
        int i = 0;
        for(auto a : mat){
            int tt = accumulate(a.begin() , a.end(), 0);
            if(tt > maxi ){maxi = tt; ans = i;}
            i++;
        }
        return {ans , maxi};
    }
};