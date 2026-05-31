class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin() , ast.end());
        long long mm = mass;
        for(auto a : ast){
            if(a > mm) return false;
            else mm += a;
        }
        return true;
    }
};