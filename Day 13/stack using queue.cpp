class MyStack {
public:
// Implement Stack using Queues
        queue<int> q;
        queue<int> p;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.empty()) return -1;
        while(q.size() > 1) {
            p.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        q.swap(p);
        
        return ans;
    }
    
    int top() {
        while(q.size() > 1) {
            p.push(q.front());
            q.pop();
        }
        int ans = q.front();
        p.push(q.front());
        q.pop();
        q.swap(p);
        return ans;
    }
    
    bool empty() {
        if(q.size() == 0) return true;
        return false;
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