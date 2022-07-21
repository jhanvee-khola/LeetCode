class Solution {
public:
    set<pair<int,int>> visit;
    int solve(int i,int j,int n){
        if(i>n){
            return 1e9;
        }
        if(i==n){
            return 0;
        }
        if(visit.find({i,j})!=visit.end()){
            return 1e9;
        }
        else{
            visit.insert({i,j});
        }
        int op1=1+solve(i,i,n);
        int op2=1+solve(i+j,j,n);
        return min(op1,op2);
    }
    int minSteps(int n) {
        //i->no. of A on the screen
        //j->no. of A on the clipboard
         return solve(1,0,n);
    }
};