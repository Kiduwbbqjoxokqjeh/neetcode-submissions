class MinStack {
public:
    stack<int> a,b;
    // idea is to store the minimum element so far 
    // on the top always.
    MinStack() {
        
    }
    
    void push(int val) {
        a.push(val);
        if(b.empty() or val <= b.top()) b.push(val);
    }
    
    void pop() {
        if(a.top() == b.top()) b.pop();
        a.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};
