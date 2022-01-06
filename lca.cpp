//Take all The Variables according to that
void dfs(int u, int p = -1) {
	par[u] = p;
	for (int v : adj[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		up[v][0] = u;
		for (int j = 1; j < LOG; j++) {
			int f = up[v][j - 1];
			int s = j - 1;
			if(f!=-1){
			up[v][j] = up[f][s];
			}
		}
		dfs(v, u);
	}
}
int getKthAncestor(int node, int k) {
	if (depth[node] < k) return -1;
	for (int j = 0; j < 18; j++) {
		cout << k>>j;
		if (1 & (k >> j)) {
			node = up[node][j];
		}
	}
	return node;
}
int LCA(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	//i am assuming node x at higher depth.
	//1.bring node x to the level of node y.
	int k = depth[x] - depth[y];
	//x ko k ancestor upar karna hai.
	x=getKthAncestor(x,k)
	if (x == y) return x;
	//Now both x and y are at the same level or depth bol sakte ho
	for (int j = LOG - 1; j >= 0; j--) {
		if (up[x][j] != up[y][j]) {
			x = up[x][j];
			y = up[y][j];
		}
	}
	return up[x][0];
}
