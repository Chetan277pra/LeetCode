class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();
        int la = n-1 , lb = m-1;
        int sa = 0 , sb = 0;
        while(la >= 0 and lb >= 0){

            bool pahla = true;

            while(pahla and la >= 0){
                if(s[la] == '#'){
                    sa++;
                    la--;
                }
                else if(sa > 0){
                    sa--;
                    la--;
                }
                else pahla = false;
            }

            bool dusra = true;

            while(dusra and lb >= 0){
                if(t[lb] == '#'){
                    sb++;
                    lb--;
                }
                else if(sb > 0){
                    sb--;
                    lb--;
                }
                else dusra = false;
            }

            if(la < 0 or lb < 0) break;

            if(s[la] != t[lb] ) break;
        // cout << la << " " << lb<<endl;
            la--;
            lb--;
            cout << la << "  " << lb << endl;
        }

        while(la >= 0){
                if(s[la] == '#'){
                    sa++;
                    la--;
                }
                else if(sa > 0){
                    sa--;
                    la--;
                }
                else break;
            }
        while( lb >= 0){
                if(t[lb] == '#'){
                    sb++;
                    lb--;
                }
                else if(sb > 0){
                    sb--;
                    lb--;
                }
                else break;
            }

        if(la == lb and la == -1) return true;
        return false;
    }
};