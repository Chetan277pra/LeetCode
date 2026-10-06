class Solution {
public:
    int minAddToMakeValid(string s) {
        string temp = "";
        for(auto a : s){
            if(!temp.empty() and temp.back() == '(' and a == ')') temp.pop_back();
            else temp.push_back(a);
            
        }
        return temp.size();
    }
};