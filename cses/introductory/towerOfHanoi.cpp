#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>>ans;

void hanoi(int n,int a,int b,int c){
    if(n==0) return;

    hanoi(n-1,a,c,b);
    ans.push_back({a,c});
    hanoi(n-1,b,a,c);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    hanoi(n,1,2,3);

    cout<<ans.size()<<"\n";
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<"\n";
    }
}