#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    int mn=__gcd(n,m);
    int cnt=0;
    for(int i=1;i*i<=mn;i++){
        if(mn%i==0){
            cnt++;
            if(i!=mn/i){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}