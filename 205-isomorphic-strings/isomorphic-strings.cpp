class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length() , m = t.length();
        vector<char> az(128 , ' ');
        map<char , char> mpp;
        for(int i = 0; i < n; i++){
            if(mpp.find(s[i]) == mpp.end()){
                if(az[t[i]] != ' ') return false;
                az[t[i]] = s[i];
                // cout<<s[i]<<" ";
                mpp[s[i]] = t[i];
            }
            else{
                if(mpp[s[i]] != t[i]) return false;
            }
        
        }
        return true;
    }
};