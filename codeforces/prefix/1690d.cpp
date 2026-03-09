#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=k;
    int cnt=0;
    for(int i=0;i<k;i++){
        if(s[i]!='B') cnt++;
    }
    ans=cnt;
    for(int i=k;i<n;i++){
        if(s[i]!='B') cnt++;
        if(s[i-k]!='B') cnt--;
        ans=min(ans,cnt);
    }

    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}