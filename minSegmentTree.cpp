vector<int> segTree;


//initialise the segment Tree.
void minSegConstruct(vector<int> &arr) {
	int n = arr.size();
	//segment tree of size 2*n
	segTree.resize(2 * n);
	//Fill the last level of tree
	for (int i = n; i < n * 2; i++) {
		segTree[i] = arr[i - n];
	}

//create upper level of tree using last level
	for (int i = n - 1; i >= 0; i--) {
		//left child and right child
		segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
	}
}




void update(int idx, int value) {
	int n = segTree.size() / 2;

//Each time we are starting from leaf node
//leaf node are at the bottom

	idx = idx + n;
	segTree[idx] = value;
//idx=1 for root
	while (idx > 1) {
		int parent = idx / 2;
		segTree[parent] = min(segTree[2 * parent], segTree[2 * parent + 1]);
		idx = idx / 2;
	}
	debug(segTree);
}



int minimumRange(int l, int r) {
//find the minimum value in the range from l to r
//l is included an r is not included
//if your r is included then do r=r+1.
	int n = segTree.size() / 2;
	l = l + n;
	r = r + n;
	int mn = INT_MAX;

	while (l < r) {
		if (l % 2) {
			mn = min(mn, segTree[l]);
			l = l + 1;
		}
		//r is not included in the range
		if (r % 2) {
			r = r - 1;
			mn = min(mn, segTree[r]);
		}
		l = l / 2;
		r = r / 2;
	}

	return mn;
}
