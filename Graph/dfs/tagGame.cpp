//https://codeforces.com/contest/813/problem/C
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>visited;
vector<int>dist;
int n,x;
 
void debug(vector<int>arr){
    for(int x:arr) cout<<x<<" ";
}
void dfs(int u,int p,vector<int>&dist){
    for(int v:adj[u]){
        if(v!=p) {
            dist[v]=dist[u]+1;
            dfs(v,u,dist);
        }
    }
}
void solve(){
    cin>>n>>x;
    adj.resize(n+1);
    dist.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>dist1(n+1,INT_MAX),dist2(n+1,INT_MAX);
    dist1[1]=0;
    dfs(1,0,dist1);
    dist2[x]=0;
    dfs(x,0,dist2);
    int mx=0;
    for(int i=1;i<=n;i++){
        if(dist1[i]>dist2[i]) mx=max(mx,dist1[i]);
    }
    cout<<2*mx<<endl;

}
int main(){
    solve();
    return 0;
}