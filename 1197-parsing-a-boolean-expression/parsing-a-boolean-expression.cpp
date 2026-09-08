class Solution {
public:
    bool parseBoolExpr(string ex) {
        stack<char> st;
        int n = ex.size();
        for(int i = 0; i < n; i++){
            char ans = ex[i];
            if(ex[i] == ')'){
                int f = 0, t= 0;
                char curr = 'd';
                while(!st.empty()){
                    char a = st.top(); st.pop();
                    if(a == '('){
                        curr = st.top(); st.pop();
                        break;
                    }
                    if(a == 't') t++;
                    else if(a == 'f') f++;
                    else curr = a;
                }
                if(curr == '&') f > 0 ? ans = 'f' : ans = 't';
                else if(curr == '|') t > 0? ans = 't': ans = 'f';
                else  {
                    if(t > 0) ans = 'f';
                    else ans = 't';
                }
            }
            st.push(ans);
        }
        char ans = st.top();
        if(ans == 't') return true;
        else return false;
    }
};