class Solution {
public:
    int n , m , k;
    bool rec(vector<vector<char>>& board , int row , int col , vector<vector<bool>>&vis, int ind , string &word){
        if(ind == k) return true;
        if(row < 0 or col < 0 or row >= n or col >= m) return false;
        bool ans = false;
        // cout << ind<< " " << row<<":"<<col << endl;
        if(vis[row][col]) return false;
        if(board[row][col] != word[ind]){
            return false;
        }
        else{
            vis[row][col] = true;
            ind++;
            ans |= (
                rec(board , row-1 , col , vis , ind, word)
                or rec(board , row , col-1 , vis , ind, word)
                or rec(board , row+1 , col , vis , ind, word)
                or rec(board , row , col+1 , vis , ind, word)
            );
            vis[row][col] = false;
        }  
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        k = word.length();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        bool ans= false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0])
                ans |= rec(board ,i , j, vis , 0 , word);
            }
        }
        return ans;
    }
};