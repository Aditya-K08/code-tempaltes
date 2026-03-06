// https://codeforces.com/contest/638/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<pair<int,int>>>adj;
vector<int>deg;
int n;
vector<int>colorId;

void dfs(int u,int par,int color){
    int c=1;
    for(auto [v,id]:adj[u]){
        if(v==par) continue;
        if(c==color) c++;
        colorId[id]=c;
        dfs(v,u,c);
        c++;
    }
}

void solve(){
    cin>>n;
    adj.resize(n+1);
    deg.assign(n+1,0);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        deg[u]++;
        deg[v]++;
    }
    colorId.assign(n+1,0);
    int ans=*max_element(deg.begin(),deg.end());
    dfs(1,0,0);
    vector<vector<int>>days(ans+1);
    for(int i=1;i<=n-1;i++){
        days[colorId[i]].push_back(i);
    }
    cout<<ans<<endl;
    for(int d=1;d<=ans;d++){
        cout<<days[d].size()<<" ";
        for(int e:days[d]) cout<<e<<" ";
        cout<<"\n";
    }

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}