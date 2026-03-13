#include<bits/stdc++.h>
using namespace std;

class DSU{

public:
    int n;
    vector<int>parent,rankv;
    DSU(int n) : n(n),parent(n),rankv(n,0){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return;
        if(rankv[u]<rankv[v]) swap(u,v);
        parent[v]=u;
        if(rankv[u]==rankv[v]) rankv[u]++;
        // return true;
    }
};


void solve(){
    int n,q;
    cin>>n>>q;
    DSU dsu(n);
    for(int i=0;i<q;i++){
        int a,u,v;
        cin>>a>>u>>v;
        if(a==0){
            dsu.unite(u,v);
        }else{
            if(dsu.find(u)==dsu.find(v)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}