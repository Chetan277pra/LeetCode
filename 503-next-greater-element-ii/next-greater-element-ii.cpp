class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        int pos = -1;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                pos = i;
            }
        }
        // cout << 
        for(int i = 0; i < n; i++){
            int j = pos - i;
            if(j < 0) j += n;
            while(!st.empty() and st.top() <= nums[j]) st.pop();
            if(st.empty()) ans[j] = -1;
            else ans[j] = st.top();
            st.push(nums[j]);
        }
        return ans;
    }
};