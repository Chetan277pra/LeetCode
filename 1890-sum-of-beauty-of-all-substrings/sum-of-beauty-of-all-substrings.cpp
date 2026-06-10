class Solution {
public:
    int check(vector<int> vec){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto a : vec) 
        if(a != 0)
        maxi = max(a , maxi), mini = min(a , mini);
        // cout<<maxi<<" "<<mini<<endl;
        return maxi - mini;
    }
    int beautySum(string s) {
        int tot = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            vector<int> temp(26 , 0);
            for(int j = i; j < n; j++){
                temp[s[j] - 'a']++;
                tot += check(temp);
                // cout<<"i : "<<i<<" j : "<<j<<" tot : "<<tot<<endl;
            }
            // cout<<endl;
        }
        return tot;
    }
};