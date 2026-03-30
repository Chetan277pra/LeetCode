class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int ans=1;
        unordered_set<int> st;
        for(auto a : nums) st.insert(a);
        for(auto a : st){
            if(st.find(a-1)==st.end()){
                int cnt=1;
                int it=a;
                while(st.find(it+1)!=st.end()){
                    it++;
                    cnt++;
                }
                ans=max(ans , cnt);
            }
        }
        return ans;
    }
};