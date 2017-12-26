
#include<stdio.h>

void insertionSort(int* list, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (list[j] <= list[j - 1]) {
				int temp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = temp;
			}
		}
	}
}

void print(int* list, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

int main() {
	int arr[5] = {4, 2, 7, 1, 3};
	insertionSort(arr, 5);
	print(arr, 5);
}
