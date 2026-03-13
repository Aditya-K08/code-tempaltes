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

    cout<<(accumulate(fac.begin(),fac.end(),0ll)-n)<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}