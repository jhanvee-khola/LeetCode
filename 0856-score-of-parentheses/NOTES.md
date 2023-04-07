```
int scoreParentheses(string s){
  stack<int> st;
  for(int i=0;i<n;i++){
    if(s[i]=='('){
      st.push(0);
    }
    else{
      if(st.top()==0){
        st.pop();
        st.push(1);
      }
      else{
        int score=0;
        while(st.top()!=0){
          score+=st.top();
          st.pop();
        }
        st.pop();
        st.push(2*score);
      }
    }
  }
  int ans=0;
  while(!st.empty()){
    ans+=st.top();
    st.pop();
  }
  return ans;
}
```
