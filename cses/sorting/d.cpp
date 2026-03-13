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
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(auto &x:a) cin>>x;
    multiset<int>ms(all(a));
    for(auto &x:b) cin>>x;
    vector<int>vis(n);
    for(int x:b){
        auto it = ms.upper_bound(x);
        if(it==ms.begin()){
            cout<<-1<<endl;
        }else{
            it--;
            cout<<*it<<endl;
            ms.erase(it);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}