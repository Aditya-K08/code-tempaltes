//https://codeforces.com/contest/862/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj;
vector<int>color;
vector<int>dist;
int n,m;
 
void debug(vector<int>arr){
    for(int x:arr) cout<<x<<" ";
}
bool dfs(int u,int c){
    color[u]=c;
    for(int v:adj[u]){
        if(color[v]==-1){
            if(!dfs(v,c^1)) return false;
        }
        else if(color[v]==color[u]){
            return false;
        }
    }
    return true;
}
void solve(){
    cin>>n;
    adj.assign(n+1,{});
    color.assign(n+1,-1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c1=0,c2=0;
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        if(color[i]==1) c1++;
        else c2++;
    }
    int ans=c1*c2-n+1;
    cout<<ans<<endl;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}