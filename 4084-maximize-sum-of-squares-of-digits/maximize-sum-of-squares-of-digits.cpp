class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum < 1)
            return "";
        if (sum > 9 * num)
            return "";
        string res = "";
        
        for (int i = 0; i < num; i++) {
            int rems = num - 1 - i;
            int maxi = 0;
            
            for (int d = 9; d >= 0; d--) {
                if (i == 0 and d == 0 and num > 1)
                    continue;
                
                int remm = sum - d;
                int maxm = 9 * rems;
                
                if (remm >= 0 and remm <= maxm) {
                    maxi = d;
                    break;
                }
            }
                res+=to_string(maxi);
                sum-=maxi;
            }
            
            if (sum != 0)
                return "";
        
        return res;
    }
};