int n;
vector<int> bitTree;
//return the sum from index-> 1 to idx.
int sum(int idx) {
	int res = 0;
	while (idx > 0) {
		res += (bitTree[idx]);
		idx = idx - ((idx) & (-idx));
	}
	return res;
}

void update(int idx, int value) {
	while (idx <= n) {
		bitTree[idx] += value; //add given value.
		idx += (idx) & (-idx);
	}
}
