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

    vector<int>dp(k+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=k;i++){
        for(int j=n-1;j>=0;j--){
            if(i>=arr[j] && dp[i-arr[j]]!=INT_MAX) dp[i]=min(dp[i],1+dp[i-arr[j]]);
        }
    }
    cout<<(dp[k]==INT_MAX ? -1 : dp[k]) <<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}