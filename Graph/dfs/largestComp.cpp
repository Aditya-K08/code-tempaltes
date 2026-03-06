//https://codeforces.com/contest/1985/problem/H1
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
void dfs(int sx,int sy){
    stack<pair<int,int>> st;
    st.push({sx,sy});
    visited[sx][sy]=1;
    compId[sx][sy]=id;

    while(!st.empty()){
        auto [x,y]=st.top();
        st.pop();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(visited[nx][ny] || grid[nx][ny]!='#') continue;

            visited[nx][ny]=1;
            compId[nx][ny]=id;
            st.push({nx,ny});
        }
    }
}

void solve(){
    cin>>n>>m;
    grid.assign(n,vector<char>(m));
    visited.assign(n,vector<bool>(m,false));
    compId.assign(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    id=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]=='#'){
                dfs(i,j);
                id++;
            }
        }
    }

    vector<int>sz(id+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='#') sz[compId[i][j]]++;
        }
    }

    int ans=0;
    for(int r=0;r<n;r++){
        set<int>s;
        int cur=0;
        for(int j=0;j<m;j++){
            if(grid[r][j]=='.') cur++;
            if(grid[r][j]=='#') s.insert(compId[r][j]);
            if(r>0 && grid[r-1][j]=='#') s.insert(compId[r-1][j]);
            if(r+1<n && grid[r+1][j]=='#') s.insert(compId[r+1][j]);
        }

        for(int x:s) cur+=sz[x];
        ans=max(ans,cur);
    }

    for(int c=0;c<m;c++){
        set<int>s;
        int cur=0;

        for(int j=0;j<n;j++){
            if(grid[j][c]=='.') cur++;
            if(grid[j][c]=='#') s.insert(compId[j][c]);
            if(c>0 && grid[j][c-1]=='#') s.insert(compId[j][c-1]);
            if(c+1<m && grid[j][c+1]=='#') s.insert(compId[j][c+1]);
        }

        for(int x:s) cur+=sz[x];
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}