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
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i>=j) dp[i]=add(dp[i],dp[i-j]);
        }
    }
    cout<<dp[n]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}