
void dfs(int ver) {
	/**
	 Take action on Current vertex after Entering the vertex.
	 **/
	for (int child : adj[ver]) {
		/** Take action on Direct child before entering the child node **/
		dfs(child);
		/**Take action  on  Direct child  after  exiting  child  node **/
	}
	/**Take action on vertex before exiting the vertex we have finish the Subtree of current vertex**/
}
