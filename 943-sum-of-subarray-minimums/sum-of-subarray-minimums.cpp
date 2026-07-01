class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        long long mod = 1e9 + 7;
        int n = arr.size();
        vector<int> nse(n) , pse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        st = stack<int> {};
        for(int i = 0; i < n; i++){
            while(!st.empty() and arr[st.top()]  > arr[i])
            st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        for(int i = 0; i < n; i++){
           
            long long ways = 1LL * (i - pse[i]) * (nse[i] - i);
            ans = (ans + (ways % mod) * arr[i]) % mod;
        }
        return (int)ans;
    }
};