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
    int n;
    cin>>n;
    vector<pair<int,int>>arr;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr.pb({x,y});
    }
    sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
        if(a.first==b.first) a.second>b.second;
        return a.first<b.first;
    });
    int ed=arr[0].second;
    int maxi=0,cnt=1;
    for(int i=1;i<n;i++){
        //cout<<arr[i].first<<" "<<arr[i].second<<endl;
        if(ed>=arr[i].first){
            cout<<ed<<" "<<arr[i].first<<endl;
            cnt++;
        }else{
            ed=arr[i].second;
            maxi=max(cnt,maxi);
            cnt=1;
        }
    }
    maxi=max(cnt,maxi);
    cout<<maxi<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}