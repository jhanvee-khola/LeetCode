class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto i:wordList){
            st.insert(i);
        }
        queue<string> q;
        q.push(beginWord);
        int steps=0;
        while(!q.empty()){
            steps++;
            int n=q.size();
            while(n--){
                string s=q.front();
                q.pop();
                if(s==endWord){
                    return steps;
                }
                for(int i=0;i<s.length();i++){
                    string t=s;
                    for(char c='a';c<='z';c++){
                        t[i]=c;
                        if(t==s){
                            continue;
                        }
                        if(st.find(t)!=st.end()){
                            q.push(t);
                            st.erase(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};