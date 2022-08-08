//->I am writing sum for segment tree


const int MAXN = int(1e5) + 5;
int n, tree[4 * MAXN];
//BUILD OPERATION
void build(vector<int> &nums, int node, int start, int end) {
	if (start == end) {
		tree[node] = nums[start];
		return;
}
	int mid = (start + end) / 2;
	build(nums, node * 2, start, mid);
	build(nums, node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] [operator what you wannt] tree[node * 2 + 1];
}

//QUERY OPERATION

//query wala 3 case-> range->[2,5]
// our range got completely overlap or inside with node range [2, 5] or [2,3] or [3,4] return karenge
// our range got partially overlap with node range[1, 4] or [3, 6];-> aur depth me jayenge
// our range does not overlap with that node[0, 1] or [6, 6] -> infinite return karenge

//l---r is a range where we have to query

//start----end is a range of current node we have to compare with l---r range
int query(int l, int r, int start, int end, int node) {
//node ke range kaise nikalenge

	//no overlap
	//Out of left Side hai.  //Out of Right Side hai 
	if ((start < l and end < l) or (start > r and end > r)) {
		return 0;
	}

	//completely overlap
	if (start >= l and end <= r) return tree[node];


	//partially overlap-> aur depth me jao
	int mid = (start + end) / 2;
	return (query(l, r, start, mid, 2 * node) [operator what you wannt] query(l, r, mid + 1, end, 2 * node + 1));

}


//UPDATE OPERATION
// update(1,0,n-1,pos,new_val)
//pos is a index where we have to update 
//left Subtree me jana hai ya right subtree me jana hai.
void update(int node, int start, int end, int pos, int new_val) {
	//Leaf Node
	if (start == end) {
		tree[node] = new_val;
		return;
	}

	int mid = (start + end) / 2;
//pos is less than mid ->left child
	if (pos <= mid) update(node * 2, start, mid, pos, new_val);
//right child
	else update(node * 2 + 1, mid + 1, end, pos, new_val);

	tree[node] = tree[node * 2] [operator what you wannt] tree[node * 2 + 1];
}


