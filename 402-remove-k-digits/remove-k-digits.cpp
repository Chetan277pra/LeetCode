class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        vector<int> nse(n , n);
        string st;
        for(auto a : num){
            if(st.empty()){
                st += a;
                continue;
            }
            // cout << k << " " <<st<<endl;
            if(k == 0) st += a;
            else{
                if(a >= st.back()) st += a;
                else {
                    while(k > 0 and !st.empty() and st.back() > a){
                        k--;
                        st.pop_back();
                    }
                    st.push_back(a);
                }
            }
        }
        while(k > 0 and !st.empty()) {k--; st.pop_back();}
        while(!st.empty() and st.front() == '0') st.erase(0 , 1);
        if(st == "") return "0";
        return st;
    }
};