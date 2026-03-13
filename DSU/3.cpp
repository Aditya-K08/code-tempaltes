#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    int n;
    vector<int>parent,rankv;

    DSU(int n):n(n),parent(n),rankv(n,0){
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v) return false;
        if(rankv[u]<rankv[v]) swap(u,v);
        parent[v]=u;
        if(rankv[u]==rankv[v]) rankv[u]++;
        return true;
    }
};

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    DSU dsu(n);

    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        edges[i]={u,v};
    }

    vector<pair<string,pair<int,int>>>queries;

    for(int i=0;i<k;i++){
        string s;
        int u,v;
        cin>>s>>u>>v;
        --u;--v;
        queries.push_back({s,{u,v}});
    }
    vector<string>ans;
    for(int i=k-1;i>=0;i--){
        string s=queries[i].first;
        int u=queries[i].second.first;
        int v=queries[i].second.second;

        if(s=="ask"){
            if(dsu.find(u)==dsu.find(v)) ans.push_back("YES");
            else ans.push_back("NO");
        }
        else{
            dsu.unite(u,v);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto s:ans){
        cout<<s<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}