class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi = -1001, sec = -1001, th = -1001;
        int mini = 1001, s = 1001 , t = 1001;
        for(auto a : nums){
            if(a > maxi){
                th = sec;
                sec = maxi;
                maxi = a;
            }
            else if(a > sec){
                th = sec;
                sec = a;
            }
            else if(a > th) th = a;

            if(a < mini){
                t = s;
                s  = mini;
                mini = a;
            }
            else if(a < s){
                t = s;
                s = a;
            }
            else if(a < t){
                t = a;
            }
        }
        // cout << maxi <<" " << sec << " " << th << endl;
        // cout << mini << " " << s << " " << t;
        if(mini*s * maxi > maxi * sec *th) return mini * s * maxi;
        return maxi * sec *th;
    }
};