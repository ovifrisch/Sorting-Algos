#include <stdio.h>


void bubbleSort(int* list, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (list[j] > list[j + 1]) {
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
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
	int list[5] = {5, 4, 3, 2, 1};
	bubbleSort(list, 5);
	print(list, 5);
}

