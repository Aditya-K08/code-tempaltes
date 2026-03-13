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
        parent[u]=v;
        // if(u==v) return;
        // if(rankv[u]<rankv[v]) swap(u,v);
        // parent[v]=u;
        // if(rankv[u]==rankv[v]) rankv[u]++;
        // return true;
    }
};


void solve(){
    int n;
    cin>>n;
    DSU dsu(n+1);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int s=dsu.find(x);
        if(s==n+1) s=dsu.find(1);
        cout<<s<<" ";
        if(s==n) dsu.unite(s,1);
        else dsu.unite(s,s+1);
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