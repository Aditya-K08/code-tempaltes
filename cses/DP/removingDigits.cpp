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
    int ans=0;

    while(n){
        int x=n,mx=0;
        while(x){
            mx=max(mx,x%10);
            x/=10;
        }
        n-=mx;
        ans++;
    }

    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}