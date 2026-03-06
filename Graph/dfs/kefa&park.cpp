https://codeforces.com/contest/580/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,c;
vector<vector<int>>adj;
vector<int>visited;
vector<int>arr;
int cnt=0;
void dfs(int u,int pt,int cats){
    visited[u]=1;
    if(arr[u-1]==1) cats++;
    else cats=0;
    bool leaf=true;
    if(cats>c) return;
    for(int v:adj[u]){
        if(!visited[v]) {
            leaf=false;
            dfs(v,u,cats);
        }
    }
    if(leaf && cats<=c) cnt++; 
}
void solve(){
    cin>>n>>c;
    arr.resize(n);
    for(auto &x:arr) cin>>x;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1,0);
    cout<<cnt<<endl;
}
signed main(){
    solve();
    return 0;
}