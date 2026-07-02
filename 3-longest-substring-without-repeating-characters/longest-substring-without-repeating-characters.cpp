class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(128 , 0);
        int ans = 0;
        int n = s.length(), l = 0;
        for(int i = 0; i < n; i++){
            vec[s[i]]++;
            while(vec[s[i]] > 1){
                vec[s[l]]--;
                l++;
            }
            ans = max(ans , i-l+1);
        }
        return ans;
    }
};