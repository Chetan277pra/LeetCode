class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int n = s.length();
        map<char , int> mpp;
        int prev = 0;
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
            while(mpp[s[i]] > 2) mpp[s[prev++]]--;
            ans = max(ans , i - prev);
        }
        return ans+1;
    }
};