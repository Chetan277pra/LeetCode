class Solution {
public:
    bool ok(vector<int> vec){
        return vec[0] > 0 and vec[1] > 0 and vec[2] > 0;
    }
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        int l = 0;
        vector<int> vec(26, 0);
        for(int i = 0; i < n; i++){
            vec[s[i] - 'a']++;
            if(ok(vec)){
                int j = l;
                while(j < i and ok(vec)) vec[s[j++] - 'a']--; 
                ans += (j-l)*(n-i);
                l = j;
            }
            // cout << i << "  " << ans << endl;
        }
        return ans;
    }
};