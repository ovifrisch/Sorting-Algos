#include<stdio.h>

void print(int* list, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
}

void merge(int* list, int leftStart, int leftEnd, int rightStart, int rightEnd) {
	int range = rightEnd - leftStart + 1;
	int temp[range];
	int left = leftStart;
	int right = rightStart;

	for (int i = 0; i < range; i++) {
		if (left > leftEnd) {
			temp[i] = list[right++];
		}
		else if (right > rightEnd) {
			temp[i] = list[left++];
		}
		else if (list[left] <= list[right]) {
			temp[i] = list[left++];
		}
		else {
			temp[i] = list[right++];
		}
	}

	for (int i = 0; i < range; i++) {
		list[leftStart++] = temp[i];
	}
}

void mergeSort(int* list, int start, int stop) {
	if (stop - start < 1) return;
	int mid = (stop + start) / 2;
	mergeSort(list, start, mid);
	mergeSort(list, mid + 1, stop);
	merge(list, start, mid, mid + 1, stop);
}

int main() {
	int list[] = {4, 2, 7, 1, 3};
	mergeSort(list, 0, 4);
	print(list, 5);
}
