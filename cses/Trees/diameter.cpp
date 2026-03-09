#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int n;
vector<int>sz;
vector<int>vis;
int ans=0;
vector<int>dist;

void dfs(int u,int par){
    for(auto v:adj[u]){
        if(v==par) continue;
        dist[v]=dist[u]+1;
        dfs(v,u);
    }
}
void solve(){
    cin>>n;
    adj.resize(n+1,{});
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist.assign(n+1,0);
    dfs(1,0);
    int far=max_element(dist.begin(),dist.end())-dist.begin();
    dist.assign(n+1,0);
    dfs(far,0);
    ans=*max_element(dist.begin(),dist.end());
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}