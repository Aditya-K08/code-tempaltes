// https://codeforces.com/contest/794/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<int>>adj;
vector<int>deg;
void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    deg.assign(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int>label(n+1,0);
    for(int i=1;i<=n;i++){
        if(deg[i]==n-1) label[i]=2;
    }
    int st=-1;
    for(int i=1;i<=n;i++){
        if(label[i]==0){
            st=i;
            break;
        }
    }
    if(st!=-1){
        label[st]=1;
        for(int v:adj[st]) if(label[v]==0 && deg[v]!=n-1) label[v]=1;
    }
    for(int i=1;i<=n;i++) if(label[i]==0) label[i]=3;

    vector<vector<bool>>visited(n+1,vector<bool>(n+1,false));
    for(int i=1;i<=n;i++){
        for(int v:adj[i]) visited[i][v]=true;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((abs(label[i]-label[j])<=1)!=visited[i][j]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<label[i]<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}