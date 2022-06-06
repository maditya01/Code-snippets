//Take all The Variables according to that
//DFS is Useful For Calculation of  Depth of each vertex
//Precomputation of up table.
void dfs(int u, int p = -1) {
	par[u] = p;
	for (int v : adj[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		up[v][0] = u;//First Ancestor is Parent
		//First Ancestor,Second Ancestor,4th Ancestor,8thAncestor,16th Ancestor,32th Ancestor and so on.
		for (int j = 1; j < LOG; j++) {
			// vertex v ka [2^jth] Ancestor:
			// 2^j= 2^(j-1) + 2^(j-1) this is the main concept involved
			int f = up[v][j - 1]; //2^(j-1)th Ancestor
			int s = j - 1; //f ka 2^(j-1)th Ancestor
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
		// update nodes at  only where set bits are present
		// k=5th ancestor chahiye 00101  2^0+2^2 
 		// k me jth bit set hai ya nhi j times right shift karo bitwise and lo 1 ke sath.
		if ( (k>>j) & 1) {
		    node = up[node][j];
		}
	}
	return node;
}
int LCA(int x, int y) {
	//i am assuming node x at higher depth.
	if (depth[x] < depth[y]) swap(x, y);	
	//1.bring node x to the level of node y.
	int k = depth[x] - depth[y];
	//x ko k ancestor upar karna hai.
	x=getKthAncestor(x,k);
	if (x == y) return x;
	//Now both x and y are at the same level or depth bol sakte ho
	for (int j = LOG - 1; j >= 0; j--) {
		if (up[x][j] != up[y][j]) {
			x = up[x][j];
			y = up[y][j];
		}
	}
	//we are returning parent of x. as LCA.
	return up[x][0];
}
