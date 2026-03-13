#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int>arr(n);
    vector<int>pos(n+1);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        pos[arr[i]]=i;
    }

    int rounds=1;
    for(int i=2;i<=n;i++)
        if(pos[i]<pos[i-1]) rounds++;

    while(m--){
        int x,y;
        cin>>x>>y;
        x--; y--;

        int a=arr[x], b=arr[y];

        set<int> s={a,b,a-1,b-1};

        for(int v:s){
            if(v>=1 && v<n){
                if(pos[v]>pos[v+1]) rounds--;
            }
        }

        swap(arr[x],arr[y]);
        swap(pos[a],pos[b]);

        for(int v:s){
            if(v>=1 && v<n){
                if(pos[v]>pos[v+1]) rounds++;
            }
        }

        cout<<rounds<<"\n";
    }
}