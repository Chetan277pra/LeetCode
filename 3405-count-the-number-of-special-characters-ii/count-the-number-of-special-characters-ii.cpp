class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> ban(26, false);
        vector<bool> cap(26 , false);
        int tot = 0;
        for(auto a : word){
            if(a >= 'A' and a <= 'Z'){
                cap[a-'A'] = true;
            }
            else {
                if(cap[a-'a']) ban[a-'a'] = true;
            }
        }
        for(auto a : word){
            if(a >= 'a' and a <= 'z' and !ban[a-'a'] and cap[a-'a']){
                // cout<<a<<" "<<tot<<endl;
                tot++; cap[a-'a'] = false;
            }
        }
        
        return tot;
    }
};