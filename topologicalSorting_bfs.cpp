
void topological_bfs() {

	for (int i = 1; i <= V; i++) {
		for (auto j : adj[i]) {
			indegree[j]++;
		}
	}

//take priority_queue or queue For correct order you can take pq
	priority_queue<int,  vector<int>, greater<int>> pq;
	int cnt = 0;//
	for (int i = 1; i <= V; i++) {
		if (indegree[i] == 0) {
			debug(i);
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();
		topo.push_back(u);
		for (int v : adj[u]) {
			if (--indegree[v] == 0) {
				pq.push(v);
			}
			cnt++;//sari edges ko traverse kar rhe ho ya nhi
		}
	}
	if (cnt != E) {
		cout << "Cycles is Present";
	} else {
		for (int i : topo) {
			cout << i << " ";
		}
	}
}
