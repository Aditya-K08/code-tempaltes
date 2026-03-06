#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    int total=n*(n+1)/2;
    if(total&1){
        cout<<"NO"<<endl;
        return;
    }
    int tar=total/2;
    int i=1,j=n;
    int sum=tar;
    vector<int>a,b;
    for(int i=n;i>=1;i--){
        if(i<=tar){
            tar-=i;
            a.push_back(i);
        }else{
            b.push_back(i);
        }
    }
    cout<<"YES"<<endl;
    cout<<a.size()<<endl;
    for(int x:a) cout<<x<<" ";
    cout<<endl;
    cout<<b.size()<<endl;
    for(int x:b) cout<<x<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}