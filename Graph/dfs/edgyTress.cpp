//https://codeforces.com/problemset/problem/1139/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<vector<int>>adj;
vector<int>vis;
int mod=1e9+7;
int add(int x,int y){
    int z=x+y;
    if(z>=mod) z-=mod;
    return z;
}

int binPow(int x,int b){
    int res=1;
    while(b){
        if(b&1) res=(res*x)%mod;
        x=x*x%mod;
        b>>=1;
    }
    return res;
}
int dfs(int u){
    int sz=1;
    vis[u]=1;
    for(auto v:adj[u]){
        if(!vis[v]) sz+=dfs(v);
    }
    return sz;
}

void solve(){
    cin>>n>>k;
    adj.resize(n+1,{});
    vis.resize(n+1,false);
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int total=binPow(n,k);
    int notGood=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int sz=dfs(i);
            notGood=add(notGood,binPow(sz,k));
        }
    }
    cout<<(total-notGood+mod)%mod<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}