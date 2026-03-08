class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> st;
        int n = nums.size();
        for(auto a : nums){
            bitset<32> b(a);
            st.insert(b.to_ulong());
        }
        int ans = 0;
        for(auto a : st){
            if(a != ans) break;
            ans++;
        }
        bitset<16> b(ans);
        string aa = b.to_string();
        for(int i = n; i < 16; i++) aa.erase(0,1);
        return aa;
    }
};