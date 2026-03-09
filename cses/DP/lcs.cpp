#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;  
    vector<int>a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    vector<int>path;
    int x=n,y=m;
    while(x>0 && y>0){
        if(a[x-1]==b[y-1]){
            path.push_back(a[x-1]);
            x--;
            y--;
        }
        else if(dp[x-1][y] > dp[x][y-1]) x--;
        else y--;
    }
    reverse(path.begin(),path.end());
    for(auto v:path) cout<<v<<" ";
}

int main(){
    solve();
    return 0;
}