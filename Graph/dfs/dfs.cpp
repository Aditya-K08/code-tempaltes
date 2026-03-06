#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> g[100005];
bool vis[100005];

void dfs(int u){
    vis[u]=true;
    cout<<u<<" ";
    for(int v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}