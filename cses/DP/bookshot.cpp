#include<bits/stdc++.h>
using namespace std;
int mod =1e9+7;
int add(int a,int b){
    a+=b;
    if(a>=mod) a-=mod;
    return a;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i-1]]+b[i-1]);
        }
    }
    cout<<dp[n][k]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}