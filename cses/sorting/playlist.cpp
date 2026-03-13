#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;

    vector<int>a(n);
    for(auto &x:a) cin>>x;

    set<int> s;

    int l=0,ans=0;

    for(int r=0;r<n;r++){
        while(s.count(a[r])){
            s.erase(a[l]);
            l++;
        }

        s.insert(a[r]);
        ans=max(ans,r-l+1);
    }

    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}