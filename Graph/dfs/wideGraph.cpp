// /https://codeforces.com/contest/1805/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj;
vector<bool>vis;
vector<int>dist;
int n,m;
void dfs(int u){
    vis[u]=true;
    for(auto v:adj[u]){
        if(!vis[v]) {
            dist[v]=dist[u]+1;
            dfs(v);
        }
    }
}

void solve(){
    cin>>n;
    adj.resize(n+1);
    vis.assign(n+1,0);
    dist.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int far=max_element(dist.begin(),dist.end())-dist.begin();
    vis.assign(n+1,0);
    dist.assign(n+1,0);
    dfs(far);
    vector<int>distA=dist;
    vis.assign(n+1,0);
    dist.assign(n+1,0);
    int far2=max_element(distA.begin(),distA.end())-distA.begin();
    dfs(far2);
    vector<int>distB=dist;
    vector<int>rad(n);
    for(int i=1;i<=n;i++){
        rad[i-1]=max(distA[i],distB[i]);
    }   
    sort(rad.begin(),rad.end());

    for(int i=1;i<=n;i++){
        int it=lower_bound(rad.begin(),rad.end(),i)-rad.begin();
        if(it==n) cout<<n<<" ";
        else cout<<it+1<<" ";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}


