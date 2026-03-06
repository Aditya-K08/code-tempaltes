//https://www.spoj.com/problems/BUGLIFE/
#include<bits/stdc++.h>
using namespace std;
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
    cin>>n>>m;
    adj.assign(n+1,{});
    color.assign(n+1,-1);
    color.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(color[i]==-1) if(!dfs(i,0)){
        cout<<"Suspicious bugs found!"<<endl;
        return ;
    }
    cout<<"No suspicious bugs found!"<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Scenario #"<<i<<":"<<endl;
        solve();
    }
    return 0;
} 