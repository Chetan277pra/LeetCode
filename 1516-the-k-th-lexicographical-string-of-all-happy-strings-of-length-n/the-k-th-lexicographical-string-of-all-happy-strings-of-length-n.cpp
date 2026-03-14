class Solution {
public:
    string getHappyString(int n, int k) {
        int tot = pow(2 , n-1)*3;
        if(k > tot) return "";
        string ans = "";
        int mod = tot/3;
        set<char> st;
        k--;
        st.insert('a');
        st.insert('b');
        st.insert('c');
        int mul = k/mod;
        if(mul == 0) ans += 'a';
        else if(mul == 1) ans += 'b';
        else ans += 'c';
        int l = mul*mod;
        int r = (mul+1)*mod - 1;
        st.erase(ans[0]);
        while(l < r){
            int si = (r-l+1)/2;
            int side = l+si;
            // left side
            if(k < side){
                char ch = ans.back();
                ans += *(st.begin());
                st.erase(ans.back());
                st.insert(ch);
                r -= si;
            }
            else{
                char ch = ans.back();
                ans += *(prev(st.end()));
                st.erase(ans.back());
                st.insert(ch);
                l += si;
            }
        }
        return ans;
    }
};





















