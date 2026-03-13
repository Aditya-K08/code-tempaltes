#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long W;
    cin>>n>>W;
    long long need=(W+1)/2;
    vector<pair<long long,int>> v;

    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        if(x>=need && x<=W){
            cout<<1<<"\n"<<i<<"\n";
            return;
        }
        if(x<W && x<need) v.push_back({x,i});
    }

    vector<int> ans;
    long long sum=0;
    for(auto &p:v){
        sum+=p.first;
        ans.push_back(p.second);
        if(sum>=need) break;
    }

    if(sum>=need && sum<=W){
        cout<<ans.size()<<"\n";
        for(int x:ans) cout<<x<<" ";
        cout<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}