class Solution {

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a,
                                             vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int n = a.size();
        int m = b.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                vector<int> temp(2, 0);
                temp[0] = max(a[i][0], b[j][0]);
                temp[1] = min(a[i][1], b[j][1]);
                if (temp[0] > temp[1])
                    continue;
                ans.push_back(temp);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                vector<int> temp(2, 0);
                temp[0] = max(a[j][0], b[i][0]);
                temp[1] = min(a[j][1], b[i][1]);
                if (temp[0] > temp[1])
                    continue;
                ans.push_back(temp);
            }
        }
        sort(ans.begin() , ans.end());
        ans.erase(unique(ans.begin() , ans.end()),ans.end());
        return ans;
    }
};