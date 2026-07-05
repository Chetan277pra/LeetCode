class MedianFinder {
public:
    vector<int> vec;
    priority_queue<int> maxheap;
    priority_queue<int , vector<int> , greater<int>> minheap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        minheap.push(num);
        maxheap.push(minheap.top()); minheap.pop();
        // cout<<minheap.size() << " ** " <<maxheap.size() << endl;
        if(maxheap.size() > minheap.size()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size() != maxheap.size()) return minheap.top();
        // cout <<minheap.top()<<"  " << maxheap.top() << endl;
        // cout<<minheap.size() << " * " <<maxheap.size() << endl;
        double ans = ((double)minheap.top() + (double)maxheap.top())/ 2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */