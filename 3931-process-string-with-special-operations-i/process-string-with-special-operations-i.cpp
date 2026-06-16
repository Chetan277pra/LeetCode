class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto a : s){
            if(a == '*')  {if(res.length() > 0) res.pop_back();}
            else if(a == '#') res += res;
            else if(a == '%' ) reverse(res.begin() , res.end());
            else res += a;
            // cout << a << " " << res << endl;
        }
        return res;
    }
};