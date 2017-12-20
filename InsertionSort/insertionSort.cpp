#include <vector>
#include <iostream>
using namespace std;

template <class T>
void insertionSort(vector<T>& list) {
	for (int i = 0; i < list.size(); i++) {
		for (int j = i; j > 0; j--) {
			if (list[j] < list[j - 1]) {
				int temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}
		}
	}
}

template <class T>
void print(vector<T> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " " ;
	}
	cout << endl;
}

int main() {
	vector<int> list = {5, 9, 3, 7, 4, 1, 2, 13, 55};
	insertionSort(list);
	print(list);
}