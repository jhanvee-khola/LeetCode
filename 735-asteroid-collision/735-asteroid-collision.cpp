class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            bool saved=true;
            if(asteroids[i]<0){
                while(!ast.empty()){
                    if(asteroids[i]*ast.top()>0){
                        break;
                    }
                    
                    if(abs(asteroids[i])>abs(ast.top())){
                        ast.pop();
                    }
                    else if(abs(asteroids[i])==abs(ast.top())){
                        ast.pop();
                        saved=false;
                        break;
                    }
                    else{
                        saved=false;
                        break;
                    }
                }
            }
            if(saved){
                ast.push(asteroids[i]);
            }
        }
        int m=ast.size(),i=m-1;
        vector<int> ans(m);
        while(!ast.empty()){
            ans[i]=ast.top();
            ast.pop();
            i--;
        }
        return ans;
    }
};