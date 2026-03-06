// https://codeforces.com/problemset/problem/2114/E
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>adj;
vector<int>vis;
vector<int>arr;
vector<int>res;
vector<int>mxv;
vector<int>mnv;

void dfs(int u,int p){
    for(int v:adj[u]){
        if(v==p) continue;
        mxv[v]=max(arr[v],arr[v]-mnv[u]);
        mnv[v]=min(arr[v],arr[v]-mxv[u]);
        dfs(v,u);
    }
}

void solve(){
    cin>>n;
    arr.assign(n+1,0);
    adj.assign(n+1,{});
    mxv.assign(n+1,INT_MIN);
    mnv.assign(n+1,INT_MAX);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    res.assign(n+1,0);
    mxv[1]=mnv[1]=arr[1];
    dfs(1,0);

    for(int i=1;i<=n;i++) cout<<mxv[i]<<" ";
    cout<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}