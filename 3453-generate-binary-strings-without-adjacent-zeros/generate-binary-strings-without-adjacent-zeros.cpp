class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> vec;
        vec.push_back("0"); vec.push_back("1");
        for(int i = 2; i <= n; i++){
            vector<string> temp;
            for(auto a : vec){
                temp.push_back(a+"1");
                if(a.back() == '1')
                    temp.push_back(a+"0");
            }
            vec = temp;
        }
        return vec;
    }
};