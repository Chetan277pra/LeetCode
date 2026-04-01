class Solution {
public:
    string res;
    // fucntion to chec whthere a strin gexist or not
    int check(string ans , string temp){
        int maxi = 0;
        for(int i = 0; i < ans.length(); i++){
            if(ans[i] == temp[0]){
                 int bda = i;
                 int chota = 0;
                 while(bda < ans.size() and chota < temp.size()){
                    if(ans[bda] != temp[chota]) break;
                    bda++; chota++;
                 }
                 if(chota == temp.size())
                 maxi = temp.size();
                 else if(bda == ans.size())
                 maxi = max(maxi , chota);
            }
        }
        return maxi;
    }


    void rec(string a, string b, string c) {
        string ans = "";
        ans += a;
        int jind = check(ans , b);

        for (int k = jind; k < b.length(); k++) {
            ans += b[k];
            // cout<<k<<" ans : "<<ans<<endl;
        }
        // cout<<"second"<<endl;
        jind = check(ans , c);

        for (int k = jind; k < c.length(); k++)
        ans += c[k];
        if(res == "") res = ans;
        if(ans.length() == res.length()) res = min(res , ans);
        else if(ans.length() < res.length()) res = ans;
    }
    string minimumString(string a, string b, string c) {
        rec(a , b , c);
        rec(a , c , b);
        rec(b , a , c);
        rec(b , c , a);
        rec( c , a , b);
        rec( c , b , a);
        return res;
    }
};