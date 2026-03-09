#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int g=gcd(a,b);
    for(int &x:arr){
        x%=g;
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    for(int i=1;i<n;i++){
        int diff=arr[i]-arr[i-1];
        ans=max(diff,ans);
    }
    ans=max(ans,arr[0]+g-arr[n-1]);
    cout<<g-ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}