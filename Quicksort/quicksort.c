#include <stdio.h>

void quicksort(int* list, int left, int right) {
	int size = right - left + 1;
	int start = left;
	if (right <= left) {
		return;
	}

	int pivot = list[left];
	int newList[size];

	int j = 0;
	for (int i = left + 1; i <= right; i++) {
		if (list[i] <= pivot) {
			newList[j++] = list[i];
		}
	}

	int posPivot = left + j;
	newList[j++] = pivot;

	for (int i = left + 1; i <= right; i++) {
		if (list[i] > pivot) {
			newList[j++] = list[i];
		}
	}

	for (int i = 0; i < size; i++) {
		list[start++] = newList[i];
	}

	quicksort(list, left, posPivot - 1);
	quicksort(list, posPivot + 1, right);
}

void print(int* list, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

int main() {
	int list[12] = {3, 4, 5, 1, 2, 45, 3, 56, 789, 23, 45, 12};
	quicksort(list, 0, 11);
	print(list, 12);
}

