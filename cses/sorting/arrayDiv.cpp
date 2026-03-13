#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()
const int INF=1e18;
const int MOD=1e9+7;
int add(int a,int b){a%=MOD;b%=MOD;return (a+b)%MOD;}
int mul(int a,int b){a%=MOD;b%=MOD;return (a*b)%MOD;}


bool feasible(vector<int>&arr,int mid,int k,int n){
    int cnt=1;
    int curr=0;
    for(int i=0;i<n;i++){
        if(curr+arr[i]>mid){
            curr=0;
            cnt++;
        }
        curr+=arr[i];
    }
    return cnt<=k;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &x:arr) cin>>x;
    int lo=*max_element(all(arr));
    int hi=accumulate(all(arr),0ll);
    int ans=hi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(feasible(arr,mid,k,n)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}