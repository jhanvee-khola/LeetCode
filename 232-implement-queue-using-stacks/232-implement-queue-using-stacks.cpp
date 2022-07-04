class MyQueue {
public:
    stack<int> front;
    stack<int> back;
    MyQueue() {
    }
    
    void push(int x) {
        back.push(x);
    }
    
    int pop() {
        while(!back.empty()){
            int a=back.top();
            back.pop();
            front.push(a);
        }
        int a=front.top();
        front.pop();
        while(!front.empty()){
            int a=front.top();
            front.pop();
            back.push(a);
        }
        return a;
    }
    
    int peek() {
        while(!back.empty()){
            int a=back.top();
            back.pop();
            front.push(a);
        }
        int a=front.top();
        while(!front.empty()){
            int a=front.top();
            front.pop();
            back.push(a);
        }
        return a;
    }
    
    bool empty() {
        return back.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */