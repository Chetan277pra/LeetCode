class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n, -1), pge(n, -1), nse(n, n), nge(n, n);
        stack<int> st;
        nge[n-1] = n;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for (int i = n-1; i > -1; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }
        long long  tot = 0;
        for(int i = 0; i < n; i++){
           tot += 1LL*nums[i]*(nge[i] - i)*(i - pge[i]);
           tot -= 1LL*nums[i]*(nse[i] - i)*(i - pse[i]);
        }
        return tot;
    }
};