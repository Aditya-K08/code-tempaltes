#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    vector<int>prefix(n+1);
    for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+arr[i];
    while(q--){
        int l,r,val;
        cin>>l>>r>>val;
        int sum=prefix[l-1]+(r-l+1)*val+prefix[n]-prefix[r];
        if(sum&1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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