

#include <bits/stdc++.h>
using namespace std;


vector<int>adj[nx];
bool vis[nx];
bool col[nx];

bool dfs(int v, int c){
	vis[v] = true;
	col[v] = c;
	for(int u : adj[v]){
		if(!vis[u]){
			if (!dfs(u,c^1)) return false;
		}
		else {
			if(col[v] == col[u]) return false;
		}
	}
	return true;	


}


