#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int mx=*max_element(arr.begin(),arr.end());
    int g=0;
    vector<int>rem(n);
    int cnt=0;
    for(int i=0;i<n;i++) {
        rem[i]=mx-arr[i];
        g=gcd(g,rem[i]);
    }
    for(int x:rem){
        cnt+=(x)/g;
    }
    cout<<cnt<<" "<<g<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin>>t;
    while(t--) solve();
}