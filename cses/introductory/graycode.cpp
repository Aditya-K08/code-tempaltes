#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    vi res;
    int size = 1 << n; 
    rep(i,0,size){
        res.pb(i ^ (i >> 1));
    }
    for (int x : res) {
        for (int i = n - 1; i >= 0; i--) {
            cout << ((x >> i) & 1);
        }
        cout << "\n";
    }
} 

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}