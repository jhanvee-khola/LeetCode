class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        //can also be done using max-heap
        int brickSum=0;
        for(int i=1;i<heights.size();i++) {
            int diff=heights[i]-heights[i-1];
            if(diff<=0){
                continue;
            }
            pq.push(diff);
            if(pq.size()>ladders) {
                brickSum+=pq.top();
                pq.pop();
            }   
            if(brickSum>bricks){
                return i-1;
            }
        }
        return heights.size()-1;    
    }
};