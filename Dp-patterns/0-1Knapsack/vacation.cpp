#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>dp1(n,0),dp2(n,0),dp3(n,0);
    int a,b,c;
    cin>>a>>b>>c;
    dp1[0]=a;
    dp2[0]=b;
    dp3[0]=c;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dp1[i]=max(dp2[i-1],dp3[i-1])+a;
        dp2[i]=max(dp1[i-1],dp3[i-1])+b;
        dp3[i]=max(dp1[i-1],dp2[i-1])+c;
    }
    cout<<max({dp1[n-1],dp2[n-1],dp3[n-1]})<<endl;
}

int main(){
    solve();
    return 0;
}