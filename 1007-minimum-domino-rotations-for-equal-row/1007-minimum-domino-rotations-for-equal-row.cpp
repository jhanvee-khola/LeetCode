class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> freq(7,0);
        int n=tops.size();
        int tile=-1;
        for(int i=0;i<n;i++){
            freq[tops[i]]++;
            
            if(tops[i]!=bottoms[i]){
                freq[bottoms[i]]++;
            }
            if(freq[tops[i]]==n){
                tile=tops[i];
            }
            if(freq[bottoms[i]]==n){
                tile=bottoms[i];
            }
        }
        if(tile==-1){
            return -1;
        }
        int tilesT=0,tilesB=0;
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                continue;
            }
            if(tops[i]==tile){
                tilesT++;
            }
            if(bottoms[i]==tile){
                tilesB++;
            }
        }
        if(tilesT<tilesB){
            return tilesT;
        }
        return tilesB;
    }
};