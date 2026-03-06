//https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> g[100005];
bool vis[100005];
vector<int>comp;
int id=1;

void dfs(int u){
    vis[u]=true;
    comp[u]=id;
    for(int v:g[u]){
        if(!vis[v]) dfs(v);
    }
}

void solve(){
    cin>>n>>m;
    comp.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            id++;
        }
    }
    vector<vector<int>>mp(id);
    for(int i=1;i<=n;i++){
        mp[comp[i]].push_back(i);
    }
    if(mp.size()==2){
        cout<<0<<endl;
    }else{
        cout<<mp.size()-2<<endl;
        for(int i=1;i<mp.size()-1;i++){
            cout<<mp[i][0]<<" "<<mp[i+1][0]<<endl;
        }
    }
}


signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}   