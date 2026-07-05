class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair < int , int> , vector<pair<int , int>>,
        greater<pair<int , int>>>pq;
        map<int , int> mpp;
        for(auto a : nums) mpp[a]++;
        for(auto a : mpp){
            pq.push({a.second , a.first});
            while(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            auto a = pq.top(); pq.pop();
            ans.push_back(a.second);
        }
        return ans;
    }
};