//https://codeforces.com/contest/540/problem/C
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
int r2,c2;
void dfs(int x,int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(adj[nx][ny]=='X' && !(nx==r2 && ny==c2)) continue;
        if(visited[nx][ny]) continue;
        dfs(nx,ny);
    }
}
void solve(){
    cin>>n>>m;
    adj.assign(n,vector<char>(m));
    visited.assign(n, vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    int r1,c1;
    cin>>r1>>c1;
    cin>>r2>>c2;
    r1--;
    c1--;
    c2--;
    r2--;
    dfs(r1,c1);
    if(!visited[r2][c2]){
        cout<<"NO"<<endl;
        return;
    }
    int deg=0;
    for(int i=0;i<4;i++){
        int nx=r2+dx[i];
        int ny=c2+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(visited[nx][ny]) deg++;
    }
    if(adj[r2][c2]=='X'){
        if(deg>=1) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }else{
        if(deg>=2) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}