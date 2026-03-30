class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> col,row;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0){
                col.insert(j);
                row.insert(i);
                }
            }
        }
        // cout<<"row"<<endl;
        for(auto a : row){
            // cout<<a<<endl;
            for(int i = 0; i < n; i++) mat[a][i] = 0;
        }
        // cout<<"col"<<endl;
        for(auto a : col){
            // cout<<a<<endl;
        for(int i = 0; i < m; i++) mat[i][a] = 0;}
    }
};