//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[],long long temp[],long long start,long long mid,long long end){
        long long int i=start,j=mid,k=start,count=0;
        while(i<mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k]=arr[i];
                i++;
                k++;
            }
            else{
                temp[k]=arr[j];
                j++;
                k++;
                count+=(mid-i);
            }
        }
        while(i<mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=end){
            temp[k]=arr[j];
            j++;
            k++;
        }
        for(i=start;i<=end;i++){
            arr[i]=temp[i];
        }
        return count;
    }
    long long int mergeSort(long long arr[],long long temp[],long long start,long long end){
        long long mid,ans=0;
        if(start<end){
            mid=(start+end)/2;
            ans+=mergeSort(arr,temp,start,mid);
            ans+=mergeSort(arr,temp,mid+1,end);
            ans+=merge(arr,temp,start,mid+1,end);
        }
        return ans;
    }
    long long int inversionCount(long long arr[], long long n){
        long long temp[n];
        return mergeSort(arr,temp,0,n-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends