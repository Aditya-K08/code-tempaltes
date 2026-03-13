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
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int lo=0;
    int sum=0;
    int cnt=0;
    map<int,int>mp;
    mp[0]=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(mp.count(sum-k)) cnt+=mp[sum-k];
        mp[sum]++;
    }
    cout<<cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}