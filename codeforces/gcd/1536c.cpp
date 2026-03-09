#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    using p=pair<int,int>;
    map<p,int>mp;
    int d=0,k=0;
    for(int i=0;i<n;i++){
        if(s[i]=='D') d++;
        else k++;
        int g=gcd(d,k);
        p r={d/g,k/g};
        mp[r]++;
        cout<<mp[r]<<" ";
    }
    cout<<endl;
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