class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto a : patterns){
            if(word.find(a) != string::npos) count++;
        }
        return count;
    }
};