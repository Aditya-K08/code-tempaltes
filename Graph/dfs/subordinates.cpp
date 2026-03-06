//https://cses.fi/problemset/task/1674/

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>subSize;
vector<vector<int>>adj;
void dfs(int st,int parent){
	subSize[st]=1;
	for(int u:adj[st]){
		if(u!=parent){
			dfs(u,st);
			subSize[st]+=subSize[u];
		}
	}
}
 
int main(){
	cin>>n;
	subSize.resize(n);
	adj.resize(n);
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		x--;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	dfs(0,-1);
	for(int x:subSize) cout<<x-1<<" ";
	return 0;
}