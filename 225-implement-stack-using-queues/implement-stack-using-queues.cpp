class MyStack {
public:
    queue<int> q1 , q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        if(empty()) return -1;
        q2 = queue<int>();
        for(int i = 0; i < n-1; i++){
            int a = q1.front(); q1.pop();
            q2.push(a);
        }
        int a = q1.front(); q1.pop();
        q1 = q2;
        return a;

    }
    
    int top() {
        if(empty()) return -1;
        int n = q1.size();
        if(empty()) return -1;
        q2 = queue<int>();
        for(int i = 0; i < n-1; i++){
            int a = q1.front(); q1.pop();
            q2.push(a);
        }
        int a = q1.front();
        q2.push(a);
        q1 = q2;
        return a;

    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */