class TopVotedCandidate {
public:
    vector<int> candidates;
    vector<int> timeStamps;
    vector<int> winners;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        candidates=persons;
        timeStamps=times;
        map<int,int> votes;
        int currWinner=-1;
        for(int i=0;i<persons.size();i++){
            votes[persons[i]]++;
            if(votes[persons[i]]>=currWinner){
                currWinner=votes[persons[i]];
                winners.push_back(persons[i]);
            }
            else{
                winners.push_back(winners[i-1]);
            }
        }
    }
    int q(int t) {
        int start=0,end=timeStamps.size();
        if(t>timeStamps[end-1]){
            return winners[end-1];
        }
        while(start<end){
            int mid=(end-start)/2+start;
            if(timeStamps[mid]>=t){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        if(timeStamps[start]!=t){
            start--;
        }
        return winners[start];
    }
};
/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */