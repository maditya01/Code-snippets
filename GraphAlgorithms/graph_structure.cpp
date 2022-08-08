
//For Writing in interview.

struct Edge {
	int u, v, wt;
};


struct Graph {

//No of vertexes and No of Edges
	int V, E;
//List of Edges.
	struct Edge* edges;
}

// Creates a graph with V vertices and E edges

struct Graph* createGraph(int V, int E) {

	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}
