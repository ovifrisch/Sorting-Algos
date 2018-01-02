#include <stdio.h>

void print(int* list, int size) {
	for (int i = 1; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void percolateDown(int* list, int currentSize, int hole) {
	int temp = list[hole];
	int child;

	for (; hole * 2 <= currentSize - 1; hole = child) {
		child = 2 * hole;
		if (child != currentSize - 1 && list[child + 1] > list[child]) {
			child++;
		}

		if (list[child] > temp) {
			list[hole] = list[child];
		}

		else {
			break;
		}
	}
	list[hole] = temp;
}

void buildHeap(int* list, int size) {
	for (int i = (size - 1) / 2; i > 0; i--) {
		percolateDown(list, size, i);
	}
}

void heapsort(int* list, int size) {
	buildHeap(list, size);
	int heapSize = size;
	for (int i = 1; i < size; i++) {
		int last = list[heapSize - 1];
		list[heapSize - 1] = list[1];
		list[1] = last;
		percolateDown(list, --heapSize, 1);
	}
}


int main() {
	int list[6] = {0, 5, 4, 3, 2, 1};
	heapsort(list, 6);
	print(list, 6);
}