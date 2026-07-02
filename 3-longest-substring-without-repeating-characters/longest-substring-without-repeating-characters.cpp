class Solution {
public:
    bool ok(vector<int> &vec){
        for(int i = 0; i < 128; i++){
            if(vec[i] > 1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(128 , 0);
        int ans = 0;
        int n = s.length(), l = 0;
        for(int i = 0; i < n; i++){
            vec[s[i]]++;
            while(!ok(vec)){
                vec[s[l]]--;
                l++;
            }
            ans = max(ans , i-l+1);
        }
        return ans;
    }
};