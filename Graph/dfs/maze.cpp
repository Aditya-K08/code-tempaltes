//https://codeforces.com/contest/378/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>>adj;
vector<vector<bool>>visited;
int n,m,k;
vector<int>dx{-1,0,1,0};
vector<int>dy{0,1,0,-1};
void debug(vector<int>arr){
    for(int x:arr) cout<<x<<" ";
}
int kt;
void dfs(int x,int y){
    if(kt==0) return;
    visited[x][y]=1;
    kt--;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(!visited[nx][ny] && adj[nx][ny]=='.') dfs(nx,ny);
    }
}
void solve(){
    cin>>n>>m>>k;
    adj.assign(n+1,vector<char>(m));
    visited.assign(n, vector<bool>(m,false));
    int x1=-1,x2=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
            if(adj[i][j]=='.') {
                cnt++;
                x1=i;
                x2=j;
            }
        }
    }
    kt=cnt-k;
    dfs(x1,x2);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && adj[i][j]=='.'){
                adj[i][j]='X';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<adj[i][j];
        cout<<endl;
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}