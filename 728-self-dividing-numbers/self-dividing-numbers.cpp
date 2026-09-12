class Solution {
public:
    bool okay(int n){
        int temp = n;
        while(n > 1){
            int rem = n%10;
            n /= 10;
            if(rem == 0 ) return false;
            if(temp%rem != 0) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left ; i <= right; i++)
        if(okay(i) ) ans.push_back(i);
        return ans;
    }
};