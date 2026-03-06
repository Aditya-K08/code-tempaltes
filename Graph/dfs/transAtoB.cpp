//https://codeforces.com/contest/727/problem/A
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>ans;
bool dfs(int n,int m){
    ans.push_back(m);
   if(n==m) return true;
   if(m<n) return false;
   int rem=m%10;
   if(rem==1){
        return dfs(n,m/10);
   }else if(m%2==0){
        return dfs(n,m/2);
   }
   return false;
}
void solve(){
    int n,m;
    cin>>n>>m;
    if(dfs(n,m)){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        for(int x:ans) cout<<x<<" ";
    }else{
        cout<<"NO"<<endl;
    }
}
signed main(){
    solve();
    return 0;
}