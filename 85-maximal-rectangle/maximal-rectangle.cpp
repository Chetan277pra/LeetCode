class Solution {
public:
    int n;
    int cal(vector<int> num){
        int area = 0;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() and num[i] < num[st.top()]){
                int bar = st.top(); st.pop();
                int pse = (!st.empty())?st.top() : -1;
                area = max(area , num[bar]* (i - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int bar = st.top(); st.pop();
            int nse = n;
            int pse = (!st.empty())? st.top() : -1;
            area = max(area , num[bar] * (nse - pse - 1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int ans = 0;
        n = mat[0].size();
        int row = mat.size();
        vector<int> num(n , 0);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == '0') num[j] = 0;
                else num[j] += 1;
            }
            // for(auto a: num) cout << a << " ";
            cout << endl;
            ans = max(ans , cal(num));
        }
        return ans;
    }
};