//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    unordered_map<int,int> freq;
    for(int i=0;i<size;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<size;i++){
        if(n!=0){
            if(freq.find(n+arr[i])!=freq.end() || freq.find(n-arr[i])!=freq.end()){
                return true;
            }
        }
        else{
            if(freq[arr[i]]>1){
                return true;
            }
        }
    }
    return false;
}