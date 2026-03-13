#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()

const int INF=1e18;
const int MOD=1e9+7;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>a(n),b(m);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;

    sort(all(a));
    sort(all(b));

    int i=0,j=0,cnt=0;

    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){
            cnt++;
            i++;
            j++;
        }
        else if(a[i]<b[j]-k){
            i++;
        }
        else{
            j++;
        }
    }

    cout<<cnt<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}