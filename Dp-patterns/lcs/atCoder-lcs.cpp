#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string str="";
    int x=n,y=m;
    while(x>0 && y>0){
        if(s[x-1]==t[y-1]){
            str.push_back(s[x-1]);
            x--;
            y--;
        }
        else if(dp[x-1][y] > dp[x][y-1]) x--;
        else y--;
    }
    reverse(str.begin(),str.end());
    cout<<str<<" ";
}

int main(){
    solve();
    return 0;
}