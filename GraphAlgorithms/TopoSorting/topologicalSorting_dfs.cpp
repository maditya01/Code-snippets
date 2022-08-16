bool visited[N];
void dfs(int source) {
	visited[source] = true;
	for (auto v : adj[source]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
  //u is Coming as topo Order 
	ans.push_back(source);
}
