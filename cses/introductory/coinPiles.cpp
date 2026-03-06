#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int a,b;
    cin>>a>>b;
    int mx = max(a,b);
    int mn = min(a,b);
    if((a+b)%3==0 && mx<=2*mn) {
        cout<<"YES"<<endl;
        return;
    }else cout<<"NO"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}