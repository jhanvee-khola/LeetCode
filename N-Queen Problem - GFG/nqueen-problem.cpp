//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<int>> grid,int x,int y){
        //check column
        for(int i=0;i<x;i++){
            if(grid[i][y]==1){
                return false;
            }
        }
        //north-west diagonal
        int i=x-1,j=y-1;
        while(i>=0 && j>=0){
            if(grid[i][j]==1){
                return false;
            }
            i--;
            j--;
        }
        //north-east diagonal
        i=x-1,j=y+1;
        while(i>=0 && j<grid.size()){
            if(grid[i][j]==1){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void help(vector<vector<int>> &ans,vector<vector<int>> &grid,vector<int> temp,int row,int n){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(grid,row,j)){
                grid[row][j]=1;
                temp.push_back(j+1);
                help(ans,grid,temp,row+1,n);
                temp.pop_back();
                grid[row][j]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> grid(n,vector<int>(n,0));
        vector<vector<int>> ans;
        vector<int> temp;
        help(ans,grid,temp,0,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends