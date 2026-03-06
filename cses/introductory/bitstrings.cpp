#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int binPow(int x,int y){
    int res=1;
    while(y){
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res%mod;
}
void solve(){
    int n;
    cin>>n;
    cout<<binPow(2,n)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}