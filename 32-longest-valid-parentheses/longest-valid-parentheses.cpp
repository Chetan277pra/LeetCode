class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0 || s.length() == 1)
            return 0;

        stack<char> st;
        stack<int> freq;
        freq.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push('(');
                freq.push(i);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    freq.pop();
                } else {
                    freq.push(i);
                }
            }
        }

        int ans = 0;
        int right = s.length();

        while (!freq.empty()) {
            int left = freq.top();
            freq.pop();
            ans = max(ans, right - left - 1);
            right = left;
        }

        return ans;
    }
};