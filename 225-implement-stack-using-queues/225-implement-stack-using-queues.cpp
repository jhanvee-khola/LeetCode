class MyStack {
public:
    queue<int> frontQ;
    MyStack() {
    }
    
    void push(int x) {
        frontQ.push(x);
    }
    
    int pop() {
        int top,sizeQ=frontQ.size();
        if(sizeQ<1){
            return -1;
        }
        for(int i=0;i<sizeQ;i++){
            top=frontQ.front();
            frontQ.pop();
            if(i!=sizeQ-1){
                frontQ.push(top);
            }
        }
        return top;
        
    }
    int top() {
        int top,sizeQ=frontQ.size();
        if(sizeQ<1){
            return -1;
        }
        for(int i=0;i<sizeQ;i++){
            top=frontQ.front();
            frontQ.pop();            
            frontQ.push(top);            
        }
        return top;
    }
    
    bool empty() {
        return frontQ.empty();
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