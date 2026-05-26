class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        vector<bool> posi(52 , false);
        for(auto  a : word){
            if(a >= 'a' and a <= 'z') posi[a-'a'+26] = true;
            else posi[a-'A'] = true;
        }
        for(int i = 0; i < 26; i++){
            count += min(posi[i] , posi[i+26]);
        }
        return count;
    }
};