for(int j=i+1;j<wordList.size();j++){
string t=wordList[j];
if(diff(s,t)==1){
adj[s].push_back(t);
adj[t].push_back(s);
}
}
}
if(adj.find(beginWord)==adj.end()){
for(int i=0;i<wordList.size();i++){
string s=wordList[i];
if(diff(beginWord,s)==1){
adj[beginWord].push_back(s);
adj[s].push_back(beginWord);
}
}
}
if(adj.find(endWord)==adj.end()){
return 0;
}
map<string,int> visit;
dfs(beginWord,endWord,adj,visit,1);
if(ans==INT_MAX){
return 0;
}
return ans;
}
};
```