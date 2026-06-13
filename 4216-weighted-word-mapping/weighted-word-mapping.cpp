class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto a : words){
            int temp = 0;
            for(auto b : a) temp += (weights[b-'a']);
            temp %= 26;
            ans += ((25-temp )+ 'a');
        }
        return ans;
    }
};