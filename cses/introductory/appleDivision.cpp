#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>arr;
int total;
int mini;

void dfs(int st,int sum){
    if(st==n){
        mini=min(mini,abs(2*sum-total));
        return;
    }
    dfs(st+1,sum+arr[st]);
    dfs(st+1,sum);
}

signed main(){
   cin>>n;
   arr.resize(n);
   for(int i=0;i<n;i++) cin>>arr[i];
   mini=LLONG_MAX;
   total=accumulate(arr.begin(),arr.end(),0ll);
   dfs(0,0);
   cout<<mini<<endl;
   return 0; 
}