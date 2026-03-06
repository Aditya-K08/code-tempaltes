#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int r,c;
        cin>>r>>c;
        int m=max(r,c);
        int val=m*m;
        int ans=0;
        if(m%2==0){
            if(r==m) ans=val-(c-1);
            else ans=(m-1)*(m-1)+r;
        }else{
            if(c==m) ans=val-(r-1);
            else ans=(m-1)*(m-1)+c;
        }
        cout<<ans<<endl;
    }    
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}