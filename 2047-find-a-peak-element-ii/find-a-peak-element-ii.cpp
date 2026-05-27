class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, r = m;
        while(l < r){
            int mid = l + (r - l)/2;
            int posi = 0, maxi = INT_MIN;
            
            for(int i = 0; i < n; i++){
                if(mat[i][mid] > maxi){
                    maxi = mat[i][mid];
                    posi = i;
                }
            }
            // cout << mid << " "<< posi <<endl;
            // return {-1 , -1};
            if(m == 1) return {posi , mid};
            else if(mid > 0 and mid < m-1 and maxi > mat[posi][mid-1] and maxi > mat[posi][mid+1])
            return {posi , mid};
            else if(mid == 0 and maxi > mat[posi][mid+1] )
            return {posi , mid};
            else if(mid == m-1 and maxi > mat[posi][mid-1])
            return {posi , mid};
            else if(maxi > mat[posi][mid-1])
            l = mid+1;
            else r = mid;
        }
        return {-1 , -1};
    }
};