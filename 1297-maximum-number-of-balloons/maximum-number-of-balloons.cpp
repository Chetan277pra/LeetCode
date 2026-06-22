class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vec(26 , 0);
        for(auto a : text) vec[a-'a']++;
        int mini = INT_MAX;
        string s = "balon";
        vec[11] /= 2;
        vec[14] /= 2;
        for(auto a : s){
            mini = min(mini , vec[a-'a']);
        }
        return mini;
    }
};