#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &x:arr) cin>>x;
    int tot=accumulate(arr.begin(),arr.end(),0);
    vector<bool>dp(tot+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++){
        for(int j=tot;j>=arr[i];j--){   
            dp[j]=dp[j] | dp[j-arr[i]];
        }
    }
    vector<int>ans;
    for(int i=1;i<=tot;i++){
        if(dp[i]) ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(int x:ans) cout<<x<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}