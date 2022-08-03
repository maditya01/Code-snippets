#include<bits/stdc++.h>
using namespace std;

//Heap is a complete binary we can use Array to store heap order
// left child-> 2*i
// right child->2*i+1
// parent -> i/2

class MyHeap {

public:

	int *heap;  //store heap array.
	int capacity;   //Maximum capacity of heap.
	int curr_Index; // curr_Index where we have to insert
	// Member Function
	int *heapSort;

	MyHeap(int capacity) {
		heap = new int[capacity + 1]; //1 based index.
		heapSort = new int[capacity + 1];
		this->capacity = capacity;
		curr_Index = 0;
	}

	void heapInsert(int val) {
		if (curr_Index == capacity + 1) {
			cout << "OverFlow No Space" << "\n";
			return;
		}
		curr_Index++;
		if (curr_Index == 1) {
			heap[curr_Index] = val;
			return;
		}

		int i = curr_Index;
		int parent = i / 2;
		while (i != 1 and heap[parent] < val) {
			heap[i]	= heap[parent] ;
			i = parent;
			parent = i / 2;
		}
		// cout << i << curr_Index << endl;
		heap[i] = val;
	}

	int extractMax() {
		if (curr_Index == 0) {
			cout << "No Element Present" << "\n";
			return INT_MAX;
		}
		return heap[1];
	}

	void heapify(int i) {
		if (i == 0) return;
		int largest = i;
		int left = 2 * i;
		int right = 2 * i + 1;
		//compare both children
		int temp = heap[i];
		if (left <= curr_Index and heap[left] > temp and heap[left] > heap[right]) {
			largest = left;
		}

		if (right <= curr_Index and heap[right] > temp and heap[right] > heap[left]) {
			largest = right;
		}
		if (largest != i) {
			swap(heap[largest], heap[i]);
			heapify(largest);
		}
	}

	void heapDelete() {
		if (curr_Index == 0) {
			cout << "No Element Present \n" << endl;
			return;
		}
		//root element is deleted.
		int maxValue = heap[1];
		cout << endl << (maxValue) << " " << curr_Index ;
		heap[1] = heap[curr_Index];
		heapSort[curr_Index] = maxValue;
		curr_Index--;
		heapify(1);
	}
};

int main() {


	int size = 7;
	// cin >> size;
	MyHeap *h = new MyHeap(size);
	for (int i = 1; i <= size; i++) {
		int val;
		cin >> val;
		h->heapInsert(val);
	}
	for (int i = 1; i <= h->curr_Index; i++) {
		cout << h->heap[i] << " " << i << endl;
	}
	// for (int i = 1; i <= h->capacity; i++) {
	// 	h->heapDelete();
	// }
	cout << endl;
	// h->insert(14);//overflow No space.
	// cout  << h->extractMax() << endl;//in O(1)we can get Maximum.
	for (int i = 1; i <= size; i++) {
		cout << h->heapSort[i] << " ";
	}

}

