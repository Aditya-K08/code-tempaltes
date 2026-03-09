#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
int n;
vector<int>sz;

void dfs(int u,int par){
    sz[u]=1;
    for(auto v:adj[u]){
        if(v==par) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void solve(){
    cin>>n;
    adj.resize(n+1);
    sz.assign(n+1,0);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<sz[i]-1<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}