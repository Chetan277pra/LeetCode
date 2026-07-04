class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int si;
    KthLargest(int k, vector<int>& nums) {
        si = k;
        for(auto a : nums) pq.push(a);
        while(pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > si)
        pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */