#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int>pref(n+1,0);

    for(int i=0;i<n;i++){
        pref[i+1]=pref[i]+(s[i]=='1');
    }

    int ans=0;
    int best=INT_MAX;

    for(int i=0;i<=n;i++){
        int left=i;
        int right=n-i;

        int ones=pref[n]-pref[i];
        int zeros=left-pref[i];

        int limit1=(left+1)/2;
        int limit2=(right+1)/2;

        if(zeros>=limit1 && ones>=limit2){
            int dist=abs(2*i-n);

            if(dist<best || (dist==best && i<ans)){
                best=dist;
                ans=i;
            }
        }
    }

    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}