//https://codeforces.com/contest/24/problem/A
#include<bits/stdc++.h>
using namespace std;
 
vector<vector<pair<int,int>>> adj;
int n;
int total=0;
int cost=0;
 
void dfs(int u,int parent){
    for(auto [v,w]:adj[u]){
        if(v==parent) continue;
        cost+=w;
        if(v==1) return;    
        dfs(v,u);
        return; 
    }
}
 
int main(){
    cin>>n;
    adj.resize(n+1);
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,0});
        adj[b].push_back({a,c});
        total+=c;
    }
    dfs(1,-1);
    cout<<min(cost,total-cost)<<endl;
}