//https://www.spoj.com/problems/KOZE/
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>>fence;
int n,m;
vector<vector<bool>>vis;
int w,s;
vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};
bool border=false;
void dfs(int x,int y){
    vis[x][y]=1;
    if(fence[x][y]=='k') s++;
    if(fence[x][y]=='v') w++;
    if(x==0 || y==0 || x==n-1 || y==m-1) border=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if(vis[nx][ny] || fence[nx][ny]=='#') continue;
        dfs(nx,ny);
    }
}
void solve(){
    cin>>n>>m;
    fence.assign(n,vector<char>(m));
    vis.assign(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>fence[i][j];
        }
    }
    int wolves=0;
    int sheeps=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && fence[i][j]!='#'){
                w=0;
                s=0;
                border=false;
                dfs(i,j);
                if(s>w){
                    sheeps+=s;
                }else{
                    wolves+=w;
                }    
            }
        }
    }
    cout<<sheeps<<" "<<wolves<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--) solve();
    return 0;
}