class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> st;
        int n = A.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            st.insert(A[i]);
            st.insert(B[i]);
            int si = st.size();
            ans.push_back(2*(i+1) - si);
        }
        return ans;
    }
};