#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,w;
    cin>>n>>w;

    vector<int>arr(n),val(n);
    for(auto &x:arr) cin>>x;
    for(auto &x:val) cin>>x;

    vector<vector<int>>dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i-1]]+val[i-1]);
            }
        }
    }

    cout<<dp[n][w]<<endl;
}


vector<int>dp(w+1,0);

for(int i=0;i<n;i++){
    for(int j=w;j>=arr[i];j--){
        dp[j]=max(dp[j],dp[j-arr[i]]+val[i]);
    }
}


int main(){
    solve();
}