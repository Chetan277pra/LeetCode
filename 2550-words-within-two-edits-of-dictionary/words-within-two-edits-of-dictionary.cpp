class Solution {
public:
    bool check(string &a , string &b){
        int tot = 0;
        int n = a.size();
        for(int i = 0; i <  n; i++){
            tot += a[i]!=b[i];
        }
        return tot < 3;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string> ans;
        int n =  queries.size();
        for(auto a : queries){
            for(auto b : dict){
                // cout<<a<<" "<<b<<" ";
                if(check(a , b)){
                    ans.push_back(a);
                    break;
                }
            }
        }
        return ans;
    }
};