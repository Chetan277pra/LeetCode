class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> vec;
        for(auto a : ast){
            if(vec.empty()) {
                vec.push_back(a);
                continue;
            }
            else if(vec.back() > 0 and a < 0){
                while(!vec.empty() and vec.back() > 0 and abs(vec.back()) < abs(a)) vec.pop_back();
                if(vec.empty()) vec.push_back(a);
                else if(vec.back() * a > 0) vec.push_back(a);
                else if(abs(vec.back()) == abs(a)) vec.pop_back();
            }
            else vec.push_back(a);
        }
        return vec;
    }
};