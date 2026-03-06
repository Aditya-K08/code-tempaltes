//https://cses.fi/problemset/task/1668/
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> color;

bool dfs(int u){
    for(int v:adj[u]){
        if(color[v]==-1){
            color[v]=1-color[u];
            if(!dfs(v)) return false;
        }
        else if(color[v]==color[u]) return false;
    }
    return true;
}

void solve(){
    cin>>n>>m;

    adj.assign(n+1,{});
    color.assign(n+1,-1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            color[i]=0;
            if(!dfs(i)){
                cout<<"IMPOSSIBLE";
                return;
            }
        }
    }

    for(int i=1;i<=n;i++) cout<<color[i]+1<<" ";
}

int main(){
    solve();
}