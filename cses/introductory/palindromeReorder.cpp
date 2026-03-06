#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    string s;
    cin>>s;
    vector<int>freq(26,0);
    int n=s.size();
    for(int i=0;i<n;i++){
        freq[s[i]-'A']++;
    }
    int cnt=0;
    char c;
    for(int i=0;i<26;i++){
        if(freq[i]&1){
            c=char(i+'A');
            cnt++;
        }
    }
    if(cnt>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    string str="";
    for(int i=0;i<26;i++){
        if(freq[i]) {
            str.append(freq[i]/2,char(i+'A'));
        }
    }
    string rev=str;
    reverse(rev.begin(),rev.end());
    if(cnt==1) cout<<str<<c<<rev<<"\n";
    else cout<<str<<rev<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}