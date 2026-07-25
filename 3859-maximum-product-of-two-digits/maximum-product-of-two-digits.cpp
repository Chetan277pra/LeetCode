class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0, secmaxi = 0;
        while(n){
            int rem = n%10;
            n /= 10;
            if(rem > maxi){
                secmaxi = maxi;
                maxi = rem;
            }
            else if(rem > secmaxi){
                secmaxi = rem;
            }
        }
        return maxi*secmaxi;
    }
};