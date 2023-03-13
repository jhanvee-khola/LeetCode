#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int zero=0,one=0,two=0,ans=0;
  map<pair<int,int>,int> diff;
  for(int i=0;i<n;i++){
    if(a[i]==0){
      zero++;
    }
    else if(a[i]==1){
      one++;
    }
    else{
      two++;
    }
    pair<int,int> d={one-zero,two-one};
    if(diff.find(d)==diff.end()){
      diff[d]=i;
    }
    else{
       ans=max(ans,i-diff[d]);
    }
  }
  cout<<ans;
  return 0;
}
