class CustomStack {
public:
    vector<int> st;
    int ind=0;
    CustomStack(int maxSize) {
        vector<int> temp(maxSize);
        st=temp;
    }
    
    void push(int x) {
        if(ind<st.size()){
            st[ind]=x;
            ind++;
        }
    }
    
    int pop() {
        if(ind==0){
            return -1;
        }
        int ans=st[ind-1];
        ind--;
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<=ind-1 && i<k;i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */