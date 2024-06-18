class MinStack {
public:

    stack<int> s;
    multiset<int> mini;

    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        mini.insert(val);
    }
    
    void pop() {
        int tp=s.top();
        s.pop();
        mini.erase(mini.find(tp));

    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
       return *mini.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */