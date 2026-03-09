#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<bool>>dp(2,vector<bool>(n+1,false));
    dp[0][0]=true;

    for(int i=0;i<=n;i++){
        if(dp[0][i]){
            if(i+a<=n) dp[0][i+a]=true;
            if(i+b<=n) dp[0][i+b]=true;
        }
    }

    for(int i=0;i<=n;i++){
        if(dp[0][i]) dp[1][i/2]=true;
    }

    for(int i=0;i<=n;i++){
        if(dp[1][i]){
            if(i+a<=n) dp[1][i+a]=true;
            if(i+b<=n) dp[1][i+b]=true;
        }
    }

    for(int i=n;i>=0;i--){
        if(dp[0][i]||dp[1][i]){
            cout<<i<<endl;
            return;
        }
    }
}

int main(){
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    solve();
    return 0;
}