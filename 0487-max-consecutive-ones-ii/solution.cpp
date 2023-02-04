int maxConsecutiveOnes(vector<int> arr){
    int ans=0,curr=0,count=0;
    for(int i=0;i<arr.size();i++){
        count++;
        if(arr[i]==0){
            curr=count;
            count=0;
        }
        ans=max(ans,count+curr);
    }
    return ans;
}
