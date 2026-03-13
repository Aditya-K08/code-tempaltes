#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    unordered_set<char> active;
    stack<char> st;

    for(char c:s){
        if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                active.erase(st.top());
                st.pop();
            }
            st.pop(); 
        }
        else{
            if(active.count(c)){
                cout<<"No\n";
                return 0;
            }
            active.insert(c);
            st.push(c);
        }
    }

    cout<<"Yes\n";
}