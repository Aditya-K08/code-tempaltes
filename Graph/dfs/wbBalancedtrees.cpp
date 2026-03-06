// https://codeforces.com/contest/1676/problem/G
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>>adj;
vector<int>arr;
vector<int>vis;
string s;
int cnt=0;
vector<int>res;
void dfs(int u){
    res[u] = (s[u-1] == 'W' ? 1 : -1);
    for(auto v:adj[u]){
        dfs(v);
        res[u]+=res[v]; 
    }
    if(res[u]==0) cnt++;
}
void solve(){
    cnt=0;
    cin>>n;
    adj.assign(n+1,{});
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    cin>>s;
    vis.assign(n+1,0);
    res.assign(n+1,0);
    dfs(1);
    cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}