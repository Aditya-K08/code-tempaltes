#include<bits/stdc++.h>
using namespace std;

set<string>ans;

void dfs(string s,int l){
    if(l==s.size()){
        ans.insert(s);
        return;
    }

    for(int i=l;i<s.size();i++){
        swap(s[l],s[i]);
        dfs(s,l+1);
    }
}

int main(){
    string s;
    cin>>s;

    dfs(s,0);

    cout<<ans.size()<<"\n";
    for(auto &x:ans) cout<<x<<"\n";
}