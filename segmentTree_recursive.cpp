//  i am writing sum for segment tree


const int MAXN = int(1e5) + 5;
int n, tree[4 * MAXN];
//BUILD OPERATION
void build(vector<int> &nums, int pos, int start, int end) {
	if (start == end) {
		tree[pos] = nums[start];
		return;
}
	int mid = (start + end) / 2;
	build(nums, pos * 2, start, mid);
	build(nums, pos * 2 + 1, mid + 1, end);
	tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}

//QUERY OPERATION

//query wala 3 case-> range->[2,5]
// our range got completely overlap or inside with node range [2, 5] or [2,3] or [3,4] return karenge
// our range got partially overlap with node range[1, 4] or [3, 6];-> aur depth me jayenge
// our range does not overlap with that node[0, 1] or [6, 6] -> infinite return karenga

int query(int l, int r, int start, int end, int pos) {
//node ke range kaise nikalenge

	//does not overlap
	if ((start < l and end < l) or (start > r and end > r)) {
		return 0;
	}

	//completely overlap
	if (start >= l and end <= r) return tree[pos];


	//partially overlap-> aur depth me jao
	int mid = (start + end) / 2;
	return (query(l, r, start, mid, 2 * pos) + query(l, r, mid + 1, end, 2 * pos + 1));

}


//UPDATE OPERATION
// update(1,0,n-1,pos,new_val)
//pos is a index where we have to update 
void update(int ind, int start, int end, int pos, int new_val) {
	//Leaf Node
	if (start == end) {
		tree[ind] = new_val;
		return;
	}

	int mid = (start + end) / 2;
//left child
	if (pos <= mid) update(ind * 2, start, mid, pos, new_val);
//right child
	else update(ind * 2 + 1, mid + 1, end, pos, new_val);

	tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
}


