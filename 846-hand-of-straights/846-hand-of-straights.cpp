class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        
        sort(hand.begin(),hand.end());
        map<int,int> freq;
        for(int i=0;i<hand.size();i++){
            freq[hand[i]]++;
        }
        int count=0;
        for(int i=0;i<hand.size();i++){
            int start=hand[i];
            int setSize=0;
            for(int j=start;j<start+groupSize;j++){
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
            if(setSize==groupSize){
                count++;
            }
        }
        return count==hand.size()/groupSize;
    }
};