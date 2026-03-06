#include <bits/stdc++.h>
using namespace std;
#define vi vector<long long>
#define rep(i,st,n) for(int i=st;i<n;i++)
#define all(x) x.begin(), x.end()
#define int long long
#define pb push_back
#define pno cout<<"NO"<<endl;
#define pyes cout<<"YES"<<endl;
using ll = long long;
 
struct point{
    int x,y;
};
 
void solve(){
    int ans=0;
    int n;
    cin>>n;
    vi arr(n);
    rep(i,0,n) cin>>arr[i];
 
    rep(i,1,n){
        if(arr[i-1]>arr[i]){
            ans+=arr[i-1]-arr[i];
            arr[i]=arr[i-1];
        }
    }
    cout<<ans<<endl;
} 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    //cin >> t;
    t=1;
    while (t--) solve();
}