class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> vec(n+1 , 0);

        for(auto a : shifts){
            int val = (a[2] == 0 ? -1 : 1);
            vec[a[0]] += val;
            vec[a[1]+1] -= val;
        }

        for(int i = 1; i <= n; i++) 
            vec[i] += vec[i-1];

        int i = 0;
        for(auto &a : s) {
            int shift = ((vec[i++] % 26) + 26) % 26;
            a = 'a' + ((a - 'a' + shift) % 26);
        }

        return s;
    }
};