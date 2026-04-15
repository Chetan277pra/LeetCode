class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {
        int ans = INT_MAX;
        int n = words.size();
        for(int i = 0; i < n; i++) if(words[i]==target){
            ans = min( ans , min(abs(i-st), n-abs(i-st)));
        }
        return (ans == INT_MAX )? -1 : ans;
    }
};