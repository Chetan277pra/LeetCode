class Solution {
public:
    int minimumEffort(vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end(), [](vector<int>a, vector<int> b) {
            int diff = (a[1] - a[0]) - (b[1] - b[0]);
            return diff > 0;
        });
        // for(auto a : vec) cout<<a.first<<" "<<a.second<<endl;
        int mini = 0, left = 0;
        // cout<<endl;
        for (auto a : vec) {
            if (left >= a[1]) {
                left -= a[0];
            } else {
                mini += (a[1] - left);
                left = a[1] - a[0];
            }
            // cout<<mini<<" "<<left<<endl;
        }
        return mini;
    }
};

