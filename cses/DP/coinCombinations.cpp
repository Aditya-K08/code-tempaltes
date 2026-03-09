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
    vector<int>dp(k+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j>=arr[i]){
                dp[j]=add(dp[j-arr[i]],dp[j]);
            }
        }
    }
    cout<<dp[k]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}