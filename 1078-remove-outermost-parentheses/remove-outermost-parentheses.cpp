class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int> temp;
        int n = s.length();
        vector<bool> skip(n , false);
        for(int i = 0; i < n ; i++){
            if(s[i] == '(') temp.push_back(i);
            else{
                if(temp.size() == 1){ 
                  skip[temp.front()] = true;
                  skip[i] = true;
                }
                temp.pop_back();
            }
            // for(auto a : temp) cout<<a<<" ";
            // cout<<endl;
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            if(!skip[i]) ans.push_back(s[i]);
        }
        return ans;
    }
};