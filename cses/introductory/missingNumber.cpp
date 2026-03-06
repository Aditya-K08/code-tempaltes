#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int>vis(n+1,0);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        vis[x]=1;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) cout<<i<<endl;
    }

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}