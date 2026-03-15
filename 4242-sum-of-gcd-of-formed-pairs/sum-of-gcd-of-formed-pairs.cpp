class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        multiset<int> pre;
        int maxi = 0;
        for(auto a : nums){
            if(a > maxi) maxi = a;
            pre.insert(__gcd(a , maxi));
        }
        long long ans = 0;
        // for(auto a : pre) cout<<a <<" ";
        int n = pre.size();
        for(int i = 0; i < (n/2); i++){
            int temp = __gcd(*pre.begin() , *prev(pre.end()) );
            pre.erase(pre.begin());
            pre.erase(prev(pre.end()));
            ans += temp;
        }
        return ans;
    }
};