#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int n;
vector<int>sz;
vector<int>vis;
int ans=0;
void dfs(int u,int par){
    for(auto v:adj[u]){
        if(v==par) continue;
        dfs(v,u);
        if(!vis[v] && !vis[u]){
            vis[v]=vis[u]=1;
            ans++;
        }
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
    ans=0;
    vis.resize(n+1,0);
    dfs(1,0);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}