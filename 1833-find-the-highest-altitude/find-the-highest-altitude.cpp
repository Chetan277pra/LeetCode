class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(gain[0]);
        int n = gain.size();
        for(int i = 1; i < n; i++){
            ans.push_back(ans[i] + gain[i]);
        }
        return *max_element(ans.begin() , ans.end());
    }
};