#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod =1e9+7;
int add(int a,int b){
    a+=b;
    if(a>=mod) a-=mod;
    return a;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<vector<int>>dp(n+1,vector<int>(k+2,0));
    if(arr[0]==0){
        for(int i=1;i<=k;i++) dp[0][i]=1;
    }else dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(arr[i]!=0 && arr[i]!=j) continue;
                dp[i][j]=add(dp[i][j],dp[i-1][j]);
                dp[i][j]=add(dp[i][j],dp[i-1][j-1]);
                dp[i][j]=add(dp[i][j],dp[i-1][j+1]);
        }
    }
    int ans=0;
    if(arr[n-1]==0){
        for(int j=1;j<=k;j++) ans=add(ans,dp[n-1][j]);
    }
    else ans=dp[n-1][arr[n-1]];
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}