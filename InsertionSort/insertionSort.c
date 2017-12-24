
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
	int size = 5;
	int arr[size];
	arr[0] = 4;
	arr[1] = 2;
	arr[2] = 7;
	arr[3] = 1;
	arr[4] = 3;
	insertionSort(arr, size);
	print(arr, size);
}
