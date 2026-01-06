
vector<int>adj[N+1],dis(N+1,0);
bool vis[N+1];

void sssp(int v, int d){
	vis[v] = true;
	dis[v] = d;
	for(int u : adj[v]){
		if(!vis[u]){
			sssp(u ,d + 1);
		}
	}
}



