#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int n){
    cout<<n<<" ";
    if(n==1) return;
    if(n&1) n=n*3+1;
    else n/=2;
    dfs(n);
}
void solve(){
    int n;
    cin>>n;
    dfs(n);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}