class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int total=0;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
            total+=piles[i];
        }
        for(int i=0;i<k;i++){
            int n=pq.top();
            pq.pop();
            int d=floor(n/2);
            total-=d;
            pq.push(n-d);
        }
        return total;
    }
};