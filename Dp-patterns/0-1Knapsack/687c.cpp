#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);
    for(int &x:arr) cin>>x;

    vector<vector<bool>>dp(k+1,vector<bool>(k+1,false));
    dp[0][0]=true;

    for(int i=0;i<n;i++){
        for(int j=k-arr[i];j>=0;j--){
            for(int k=j;k>=0;k--){
                if(dp[j][k]){
                    dp[j+arr[i]][k+arr[i]]=true;
                    dp[j+arr[i]][k]=true;
                }
            }
        }
    }
    vector<int>ans;
    for(int x=0;x<=k;x++){
        if(dp[k][x]) ans.push_back(x);
    }

    cout<<ans.size()<<"\n";
    for(int x:ans) cout<<x<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}