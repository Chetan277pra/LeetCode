class Solution {
public:
    vector<string> ans;
    void rec(int a , int b , int n , string temp){
        if(a == n and b == n) 
        ans.push_back(temp);
        if(a > b){
            temp.push_back(')');
            rec(a , b + 1 , n , temp);
            temp.pop_back();
            if(a < n){
                temp.push_back('(');
                rec(a + 1 , b ,n ,  temp);
                temp.pop_back();
            }
        }
        else if(a < n) {
                temp.push_back('(');
                rec(a + 1 , b ,n , temp);
                temp.pop_back();
        }
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        rec(0 , 0  , n , temp);
        return ans;
    }
};