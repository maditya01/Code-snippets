//Variables have their usual Meaning
//Edges is a vector of vector
//dis,par is a V size vector
// https://media.geeksforgeeks.org/wp-content/uploads/bellmanford1.png-> TAKE THIS AS AN EXAMPLE.
void bellmanFord(int source) {
	int x;
	for (int i = 0; i < V; i++) {
		x = -1;
		for (int j = 0; j < E; j++) {
			int u = edges[j][0];
			int v = edges[j][1];
			int wt = edges[j][2];
			if (dis[u] < INF) {
				if (dis[v] > dis[u] + wt) {
					//Why we are comparing with -INF because
					//distance can be -ve can be cross overflow
					dis[v] = max(-INF, dis[u] + wt);
					parent[v] = u;
					x = v;
				}
			}
		}
	}
	if (x == -1) {
		cout << "NO Negative CYCLE IS PRESENT" << endl;
	} else {
		cout << "Negative Cycle is Preseent";
	}
}
