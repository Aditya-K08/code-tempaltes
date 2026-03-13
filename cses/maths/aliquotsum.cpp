#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;

    vector<int>fac;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            fac.push_back(i);
            if(i!=n/i){
                fac.push_back(n/i);
            }
        }
    }

    int sum =(accumulate(fac.begin(),fac.end(),0ll)-n);
    if(sum>n) cout<<"abundant"<<endl;
    else if(sum<n) cout<<"deficient"<<endl;
    else cout<<"perfect"<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}