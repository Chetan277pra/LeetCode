class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        int n = s.length();
        vector<vector<int>> ind(26 , vector<int>());
        for(int i = 0; i < n; i++) ind[s[i] - 'a'].push_back(i);
        // for(auto a : ind){
        //     for(auto b : a) cout << b << " ";
        //     cout << endl;
        // }
        for(auto a : words){
            int i = -1;
            int t = a.length();
            int j = 0;
            for(j = 0; j < t; j++){
                auto it = lower_bound(ind[a[j]-'a'].begin() , ind[a[j]-'a'].end() , i );
                if(it == ind[a[j]-'a'].end()) break;
                i = *it+1;
            }
            if(j == t) count++;
        }
        return count;
    }
};