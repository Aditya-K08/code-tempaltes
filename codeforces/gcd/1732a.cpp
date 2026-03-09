#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int g=0;
    int cst=n;
    for(int i=0;i<n;i++){
        int x=arr[i];
        g=gcd(g,x);
        if((i+1)&1 && ~x&1){
            cst=min(cst,n-i);
        }else if(~(i+1)&1 && x&1){
            cst=min(cst,n-i);
        }
    }
    if(g==1){
        cout<<0<<endl;
        return;
    }
    cout<<cst<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}