class Solution {
public:
    string frequencySort(string s) {
        map<char , int>  mpp;
        for(auto a : s) mpp[a]++;
        vector<pair<char , int >> v(mpp.begin() , mpp.end());

        sort(v.begin() , v.end() , [](pair<char, int>a , pair<int , int>b){
            return a.second > b.second;
        } );
        string ans = "";
        for(auto a : v){
            while(a.second > 0){
                ans += a.first;
                a.second--;
            }
        }
        return ans;
    }
};