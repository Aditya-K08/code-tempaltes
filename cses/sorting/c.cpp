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
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    sort(all(arr));
    int l=0,r=n-1;
    int cnt=0;
    while(l<=r){
        if(arr[l]+arr[r]>x){
            r--;
        }else{
            l++;
            r--;
        }
        cnt++;
    }
    cout<<cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}