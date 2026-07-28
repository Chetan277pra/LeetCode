class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> vec(26 , 0);
        for(auto a : s){
            vec[a-'a']++;
        }
        string middle = "";
        string res = "";
        for(int i = 0; i < 26; i++){
            int mid = vec[i]/2;
            if(vec[i]%2) middle = i+'a';
            for(int j = 0; j < mid; j++) res += ('a' + i);
        }
        string temp = res;
        res += middle;
        reverse(temp.begin() , temp.end());
        res += temp;
        return res;
    }
};