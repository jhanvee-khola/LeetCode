class Solution {
public:
    int minDiff=INT_MAX;
    void change(deque<int> &dq,int count){
        if(count==3){
            minDiff=min(minDiff,dq.back()-dq.front());
            return;
        }
        int first=dq.front();
        dq.pop_front();
        change(dq,count+1);
        dq.push_front(first);
        int last=dq.back();
        dq.pop_back();
        change(dq,count+1);
        dq.push_back(last);
    }
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<5){
            return 0;
        }
        sort(nums.begin(),nums.end());
        deque<int> dq;
        for(int i=0;i<n;i++){
            dq.push_back(nums[i]);
        }
        change(dq,0);
        return minDiff;
    }
};