class Solution {
public:
    bool ok(vector<int> &vec , int k){
        int tot = accumulate(vec.begin() , vec.end() , 0);
        int maxi = *max_element(vec.begin() , vec.end());
        int left = tot-maxi;
        return left <= k;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> vec(26 , 0);
        int l = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            vec[s[i] - 'A']++;
            while(l <= i and !ok(vec , k)){
                vec[s[l] - 'A']--; 
                l++;
            }
            ans = max(ans , i-l+1);
        }
        return ans;
    }
};