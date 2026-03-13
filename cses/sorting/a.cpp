#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()

const int INF=1e18;
const int MOD=1e9+7;
int add(int a,int b){a%=MOD;b%=MOD;return (a+b)%MOD;}
int mul(int a,int b){a%=MOD;b%=MOD;return (a*b)%MOD;}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    cout<<arr.size()<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}