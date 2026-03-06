// https://codeforces.com/contest/982/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<vector<char>>grid;
vector<vector<int>>compId;
vector<vector<bool>>visited;
int id=1;
vector<int>dx{-1,0,1,0};
vector<int>dy{0,1,0,-1};
int res=0;
vector<int>visi;
vector<vector<int>> adjL;
int dfs2(int u,int p){
    int sz=1;
    for(int v:adjL[u]){
        if(v==p) continue;
        int child=dfs2(v,u);
        if(child%2==0) res++;
        else sz+=child;
    }
    return sz;
}
void sizeCal(){
    cin>>n;
    adjL.resize(n+1);
    visi.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    if(n&1){
        cout<<-1<<endl;
        return ;
    }
    dfs2(1,0);
    cout<<res<<endl;
}

signed main(){
    int t=1;
    //cin>>t;
    while(t--){
        //solve();
        sizeCal();
    }
    return 0;
}