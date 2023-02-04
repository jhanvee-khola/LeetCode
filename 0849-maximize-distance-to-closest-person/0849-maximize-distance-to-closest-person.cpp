class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0,n=seats.size(),prevOcc=-1;
        //prevOcc -> last occupied seat
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                if(prevOcc<0){
                    ans=i;
                }
                else{
                    ans=max(ans,(i-prevOcc)/2);
                }
                prevOcc=i;
            }
        }
        ans=max(ans,n-prevOcc-1);
        return ans;
    }
};