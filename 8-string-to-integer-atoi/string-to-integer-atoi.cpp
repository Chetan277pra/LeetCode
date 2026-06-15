class Solution {
public:
    bool neg = false;
    int mod = 1e9 + 7;
    int n;
    string rec(string& s , int ind, bool zero, bool start){
        if(ind == n) return "";
        if(s[ind] == ' ' and !start){
            return rec(s , ind+1 , zero , start);
        }
        else if((s[ind] == '+' or s[ind] == '-') and !start){
            if(s[ind] == '-' ) neg = true;
            return rec(s , ind+1 , zero , true);
        }
        else if(s[ind] < '0' or s[ind] >'9') return "";
        if(s[ind] == '0' and zero) return rec(s , ind+1 , zero, true);
        // cout << s[ind] << " " << ind << endl;
        return  s[ind] + rec(s , ind+1, false, true);
        
    }
    long long ans = 0;
    void stoint(string s , int ind){
        if(ind == n) return;
        ans = (ans*10) + (s[ind] - '0');
        if(ans > INT_MAX) {
            ans = (long long)INT_MAX + 100;
            return;
        }
        stoint(s , ind+1);
    }
    int myAtoi(string s) {
        n = s.length();
        string temp = rec(s , 0 , true, false);
        n = temp.length();
        // cout << temp << endl ;
        stoint(temp , 0);
        if(neg and ans > INT_MAX) return INT_MIN;
        else if(neg) ans = -ans;
        else if(ans > INT_MAX) ans = INT_MAX;
        return ans;
    }
};