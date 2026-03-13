#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    stack<int>st;
    st.push(-1);

    int maxi=0,cnt=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }else{
                int len=i-st.top();
                if(len>maxi){
                    maxi=len;
                    cnt=1;
                }else if(len==maxi){
                    cnt++;
                }
            }
        }
    }

    if(maxi==0) cout<<0<<" "<<1;
    else cout<<maxi<<" "<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}