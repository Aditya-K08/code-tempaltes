#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()
const int INF=1e18;
const int MOD=1e9+7;
int add(int a,int b){a%=MOD;b%=MOD;return (a+b)%MOD;}
int mul(int a,int b){a%=MOD;b%=MOD;return (a*b)%MOD;}


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    unordered_map<int,int>mp;
    int cnt=0;
    int uniq=0;
    int lo=0;
    for(int i=0;i<n;i++){
        if(!mp.count(arr[i])){
            uniq++;
        }
        while(lo<n && uniq>k){
            mp[arr[lo]]--;
            if(mp[arr[lo]]==0){
                uniq--;
                mp.erase(arr[lo]);
            }
            lo++;
        }
        mp[arr[i]]++;
        cnt+=(i-lo+1);
    }
    cout<<cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}