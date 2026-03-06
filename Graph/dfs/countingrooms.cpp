// https://cses.fi/problemset/task/1192/
#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define ll long long
#define vi vector<int>
#define rep(i,st,n) for(int i=0;i<n;i++)
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
int n,m;
vector<vector<char>>adj;
vector<vector<bool>>visited;
vector<int>dx={-1,0,0,1};
vector<int>dy={0,1,-1,0};
void dfs(int x,int y){
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(!visited[nx][ny] && adj[nx][ny]=='.'){
                dfs(nx,ny);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    adj.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    int comp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && adj[i][j]=='.'){
                dfs(i,j);
                comp++;
            }
        }
    }
    cout<<comp<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}