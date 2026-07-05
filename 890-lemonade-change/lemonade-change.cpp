class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0 , b = 0 , c = 0;
        for(auto x : bills){
            if(x == 5) a++;
            else if(x == 10){
                if(a > 0) a--;
                else return false;
                b++; 
            }
            else{
                if(a == 0) return false;
                if(b > 0){
                    b -= 1;
                    a -= 1;
                }
                else if(b == 0){
                    if(a > 2){
                        a -= 3;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};