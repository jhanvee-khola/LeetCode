class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,isum=0,esum=0;
        for(int i=0;i<arr.size();i++){
            isum+=i;
            esum+=arr[i];
            if(isum==esum){
                ans++;
            }
        }
        return ans;
    }
};