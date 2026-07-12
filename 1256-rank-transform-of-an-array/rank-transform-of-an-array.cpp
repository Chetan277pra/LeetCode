class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int , int>> vec;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            vec.push_back({arr[i] , i});
        sort(vec.begin() , vec.end());
        vector<int> ans(n , 1);
        int curr = 1;
        for(int i = 1; i < n; i++){
            ans[vec[i-1].second] = curr;
            curr += vec[i-1].first != vec[i].first;
            ans[vec[i].second] = curr;
        }
        return ans;
    }
};