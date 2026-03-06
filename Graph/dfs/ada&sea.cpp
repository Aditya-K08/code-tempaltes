// https://www.spoj.com/problems/ADASEA/
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>>adj;
vector<vector<bool>>vis;
int n,m;
vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
int id=1;
unordered_map<int,int>comp;
void dfs(int x,int y){
    stack<pair<int,int>> st;
    st.push({x,y});
    vis[x][y]=true;
    while(!st.empty()){
        auto [cx,cy]=st.top();
        st.pop();
        comp[id]++;
        for(int i=0;i<4;i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(adj[nx][ny]=='#' && !vis[nx][ny]){
                vis[nx][ny]=true;
                st.push({nx,ny});
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    adj.assign(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    comp.clear();
    id=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='#' && !vis[i][j]){
                dfs(i,j);
                id++;
            }
        }
    }
    int quo=0;
    for(auto [f,s]:comp){
        quo+=s*s;
    }
    int div=n*m;
    int d=gcd(quo,div);

    quo/=d;
    div/=d;
    if(div==1){
        cout<<quo<<endl;
    }else{
        cout<<quo<<" / "<<div<<endl;    
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}