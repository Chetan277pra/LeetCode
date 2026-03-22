class Solution {
    int n;
    void rotate(vector<vector<int>>& mat){
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++) swap(mat[i][j] , mat[j][i]);
        }
        // now row reverse
        for(auto &a : mat) reverse(a.begin() , a.end());
    }
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        for(int i = 0; i < 4; i++){
            if(check(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }
};