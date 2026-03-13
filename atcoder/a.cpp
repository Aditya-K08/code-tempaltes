#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    int n;
    cin>>n;
    vector<ll>arr(n);
    for(auto &x:arr) cin>>x;
    map<int,ll>mp;
    set<int>s;
    for(auto x:arr){
        s.insert(x);
        s.insert(x+1);
        mp[x]++;
    }
    int last=0;
    int ans=0;
    for(int x:s){
        int y=mp[x];
        ans+=max(0,y-last);
        last=y;
    }
    cout<<ans<<endl;
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}