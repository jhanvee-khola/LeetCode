class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,k=0;
        int cnt=1;
        while(i<chars.size()-1){
            if(chars[i]==chars[i+1]){
                cnt++;
            }
            else{
                chars[k++]=chars[i];
                if(cnt!=1){
                    string count=to_string(cnt);
                    for(int j=0;j<count.length();j++){
                        chars[k++]=count[j];
                    }
                }
                cnt=1;
            }
            i++;
        }
        chars[k++]=chars[i];
        if(cnt!=1){
            string count=to_string(cnt);
            for(int j=0;j<count.length();j++){
                chars[k++]=count[j];
            }
        }
        return k;
    }
};