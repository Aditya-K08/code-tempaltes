// https://codeforces.com/contest/767/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj;
int sum=0,n;
vector<int>arr,ans;
int tar,root;
int  dfs(int u,int p){
    int sum=arr[u];
    for(int v:adj[u]){
        if(v==p) continue;
        sum+=dfs(v,u);
    }
    if(sum==tar && u!=root && ans.size()<2){
        ans.push_back(u);
        return 0;
    }
    return sum;
}
void solve(){
    cin>>n;
    adj.resize(n+1);
    sum=0;
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        sum+=v;
        arr[i]=v;
        if(u==0){
            root=i;
        }else{
            adj[u].push_back(i);
            adj[i].push_back(u);
        }
    }
    if(sum%3!=0){
        cout<<-1<<endl;
        return;
    }
    tar=sum/3;
    ans.clear();
    dfs(root,0);
    if(ans.size()<2){
        cout<<-1<<endl;
        return;
    }else{
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}