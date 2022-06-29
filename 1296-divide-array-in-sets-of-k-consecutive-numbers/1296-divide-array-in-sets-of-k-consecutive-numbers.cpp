class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0){
            return false;
        }
        
        sort(nums.begin(),nums.end());
        map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            int start=nums[i];
            int setSize=0;
            for(int j=start;j<start+k;j++){
                if(freq.find(j)!=freq.end()){
                    if(freq[j]==1){
                        freq.erase(j);
                    }
                    else{
                        freq[j]--;
                    }
                    setSize++;
                }
                else{
                    break;
                }
            }
            if(setSize==k){
                count++;
            }
        }
        return count==nums.size()/k;
    }
};