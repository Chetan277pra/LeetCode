class Solution {
public:
    bool sumGame(string num) {
        int f = 0 , s= 0;
        int n = num.size();
        int tot = 0;
        for(int i = 0; i < n/2; i++){
            if(num[i] == '?'){
                tot++;
                continue;
            }
            f += (num[i]-'0');
        }
        for(int i = n/2; i < n; i++){
            if(num[i] == '?'){
                tot--;
                continue;
            }
            s += (num[i]-'0');
        }
        if(tot == 0) return f != s;
        if(tot%2) return true;
        if(tot < 0){
            if(s > f) return true;
            return (f-s) != (abs(tot-1)/2)*9;
        }
        else{
            if(f > s) return true;
            return (s - f) != (abs(tot+1)/2)*9;
        }

    }
};
// 14 14