class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++) ans[i] = i+1;
        // int run = 1;
        // int temp = n;
        // while(temp > 0){
        //     run*=temp--;
        // }
        for(int i = 0 ; i < k-1 ; i++) next_permutation(ans.begin() , ans.end());
        string aa = "";
        for(auto a : ans) aa+=(to_string(a));
        return aa;
    }
};