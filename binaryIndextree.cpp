int n;
vector<int> bitTree;
//return the sum from index-> 1 to idx.
//Given index kis-kis range se milkar bana hai
//For example idx= 13-> [13,13] idx= 12->[9,12] idx=8->[1,8] idx=0

int sum(int idx) {
	int res = 0;
	while (idx > 0) {
		res += (bitTree[idx]);
		//Extract the last set bit from index
		idx = idx - ((idx) & (-idx));
	}
	return res;
}

void update(int idx, int value) {
	while (idx <= n) {
		bitTree[idx] += value; //add given value.
		Add the last set bit to the index
		idx += (idx) & (-idx);//Given idx kha kha contribute karega
// 		[1-8] each element from 1-8 is contributing in to 8th index
	}
}

void build(vector<int> &nums) {
	for (int i = 1; i <= n; i++) {
		update(i, nums[i - 1]);
	}
}
