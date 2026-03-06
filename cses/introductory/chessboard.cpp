#include<bits/stdc++.h>
using namespace std;

vector<string>board(8);
bool col[8],diag1[15],diag2[15];
int ans=0;

void dfs(int row){
    if(row==8){
        ans++;
        return;
    }

    for(int c=0;c<8;c++){
        if(board[row][c]=='*') continue;
        if(col[c]||diag1[row+c]||diag2[row-c+7]) continue;
        col[c]=diag1[row+c]=diag2[row-c+7]=1;
        dfs(row+1);
        col[c]=diag1[row+c]=diag2[row-c+7]=0;
    }
}

int main(){
    for(int i=0;i<8;i++) cin>>board[i];
    dfs(0);
    cout<<ans<<"\n";
}