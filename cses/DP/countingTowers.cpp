#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
const int N=1000005;

int dp1[N],dp2[N];

int add(int a,int b){
    a+=b;
    if(a>=mod) a-=mod;
    return a;
}

int mul(long long a,long long b){
    return (a*b)%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp1[1]=1;
    dp2[1]=1;

    for(int i=2;i<N;i++){
        dp1[i]=add(mul(4,dp1[i-1]),dp2[i-1]);
        dp2[i]=add(dp1[i-1],mul(2,dp2[i-1]));
    }

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<add(dp1[n],dp2[n])<<"\n";
    }
}