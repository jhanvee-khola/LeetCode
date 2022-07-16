class Solution {
public:
    int fillCups(vector<int>& amt) {
        priority_queue<int> pq;
        for(int i=0;i<3;i++){
            if(amt[i]){
                pq.push(amt[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            if(pq.size()==1){
                ans+=pq.top();
                return ans;
            }
            int max1=pq.top();
            pq.pop();
            int max2=pq.top();
            pq.pop();
            max1--;
            max2--;
            ans++;
            if(max1){
                pq.push(max1);
            }
            if(max2){
                pq.push(max2);
            }
        }
        return ans;
    }
};