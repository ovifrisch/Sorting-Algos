#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T>& list) {
	for (int i = 1; i < list.size(); i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}


template <typename T>
void percolateDown(vector<T>& list, int hole, int currentSize) {
	int child;
	T tmp = list[hole];

	for (; hole * 2 <= currentSize - 1; hole = child) {
		child = hole * 2;
		if (child != currentSize - 1 && list[child + 1] > list[child]) {
			++child;
		}
		if (list[child] > tmp) {
			list[hole] = list[child];
		}
		else {
			break;
		}
	}
	list[hole] = tmp;
}


template <typename T>
void buildHeap(vector<T>& list) {
	for (int i = (list.size() - 1) / 2; i > 0; i--) {
		percolateDown(list, i, list.size());
	}
}


template <typename T>
void heapSort(vector<T>& list) {
	buildHeap(list);
	int heapSize = list.size();
	for (int i = 1; i < list.size(); i++) {
		T last = list[heapSize - 1];
		list[heapSize - 1] = list[1];
		list[1] = last;
		percolateDown(list, 1, --heapSize);
	}
}

int main() {
	vector<int> heap = {0, 1, 2, 3, 4, 5, 6, 7};
	heapSort(heap);
	print(heap);
}


