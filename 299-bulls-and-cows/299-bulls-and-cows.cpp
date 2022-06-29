class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        int n=secret.length();
        vector<bool> used(n,false);
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
                used[i]=true;
            }
            else{
                size_t ind=guess.find(secret[i]);
                if(ind!=string::npos){
                    if(used[ind] || secret[ind]==guess[ind]){
                        while(ind!=string::npos && (used[ind] || secret[ind]==guess[ind])){
                            ind=guess.find(secret[i],ind+1);
                        }
                        if(ind!=string::npos){
                            cows++;
                            used[ind]=true;
                        }
                    }
                    else{
                        cows++;
                        used[ind]=true;
                    }
                }
            }
        }
        string ans=to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};