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
    vi arr;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    if(n==4){
        cout<<"2 4 1 3"<<endl;
        return;
    }
    if(n<4) {
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    for(int i=1;i<=n;i+=2){
        arr.pb(i);
    }
    for(int i=2;i<=n;i+=2){
        arr.pb(i);
    }
    rep(i,0,n) cout<<arr[i]<<" ";
} 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    //cin >> t;
    t=1;
    while (t--) solve();
